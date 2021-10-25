

var cp = require('child_process');




class BleConnect {
  bluetoothCTL:any;
  deviceAddress = "";
  character = "";
  pingInterval = 0;
  onNotifyCallback:any;
  isConnected = false;
  checkInterval = 5000;
  isBluetoothTryingToConnect = false
  timeout:any;
  msgBuf = "";
  lastMsg = "";
  lastCallIn = 0;
  regex = new RegExp("([a-z0-9]{2} {1}){3,} +([a-zA-Z0-9_, *!-]{16})$",'');




  constructor(deviceAddress:string, characterP:string, pingInterval:number, callback:any) {   
    this.bluetoothCTL = cp.spawn('bluetoothctl');
    this.bluetoothCTL.stdout.setEncoding('utf8')
    this.bluetoothCTL.stdout.on("data", (data:any)=> this.bluetoothCTLDataReceived(data));

    this.deviceAddress = deviceAddress;
    this.character = characterP;
    this.pingInterval = pingInterval;
    this.onNotifyCallback = callback;

    this.setTimeoutAction();
  }




  setTimeoutAction() {
    clearTimeout(this.timeout);

    this.timeout = setTimeout(async ()=> {
      if (!this.isBluetoothTryingToConnect && !this.isConnected) {
        this.isBluetoothTryingToConnect = true;
        this.bluetoothCTL.stdin.write("connect " + this.deviceAddress + "\n");
      }

      this.setTimeoutAction();

    }, this.checkInterval);
  }


  timeoutAfterMsgToCheckForConnected() {
    if (this.isConnected && Date.now() - this.lastCallIn > this.pingInterval + 5000) {
      this.bluetoothCTL.stdin.write("back\n");
      setTimeout(()=> {this.bluetoothCTL.stdin.write("disconnect " + this.deviceAddress + "\n");}, 200);
      this.isConnected = false;
      this.setTimeoutAction();
    }
  }

  bluetoothCTLDataReceived(data:any) {
    if (data.includes("Failed to connect")) {
      this.isBluetoothTryingToConnect = false;

    } else if (data.includes("Connection successful")) {
      this.isBluetoothTryingToConnect = false;
      this.isConnected = true;
      setTimeout(()=> {this.bluetoothCTL.stdin.write("menu gatt\n");}, 3000);
      setTimeout(()=> {this.bluetoothCTL.stdin.write("select-attribute " + this.character + "\n");}, 4000);
      setTimeout(()=> {this.bluetoothCTL.stdin.write("notify on\n");}, 5000);
    }

    let lines:string[] = data.split("\n");

    lines.forEach(ll=> {
      let l = ll.trim().replace(/^\s+|\s+$/g, '');
      let regexMatch = l.match(this.regex);

      if (regexMatch) {
        let msg = regexMatch[regexMatch.length - 1].trim();

        if (msg[0] == "*") {
          this.msgBuf = msg;
        }

        if (msg[0] != "*" && msg[msg.length-1] != "!") {
          this.msgBuf += msg;
        }

        if (msg[msg.length-1] == "!") {
          this.msgBuf += (msg[0] == "*") ? "" : msg;
          let m = this.msgBuf.substring(1, this.msgBuf.length -1);
          this.lastMsg = m;
          this.msgBuf = "";
          this.lastCallIn = Date.now();
          this.onNotifyCallback(m);

          setTimeout(()=> { this.timeoutAfterMsgToCheckForConnected(); }, this.pingInterval + 5200);
        }
      }
    })
  }
}




export { BleConnect }


