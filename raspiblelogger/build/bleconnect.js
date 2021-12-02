"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.BleConnect = void 0;
var cp = require('child_process');
class BleConnect {
    constructor(deviceAddress, characterP, pingInterval, callback) {
        this.deviceAddress = "";
        this.character = "";
        this.pingInterval = 0;
        this.isConnected = false;
        this.checkInterval = 5000;
        this.isBluetoothTryingToConnect = false;
        this.msgBuf = "";
        this.lastMsg = "";
        this.lastCallIn = 0;
        this.regex = new RegExp("([a-z0-9]{2} {1}){3,} +([a-zA-Z0-9_, *!-]{16})$", '');
        this.bluetoothCTL = cp.spawn('bluetoothctl');
        this.bluetoothCTL.stdout.setEncoding('utf8');
        this.bluetoothCTL.stdout.on("data", (data) => this.bluetoothCTLDataReceived(data));
        this.deviceAddress = deviceAddress;
        this.character = characterP;
        this.pingInterval = pingInterval;
        this.onNotifyCallback = callback;
        this.setTimeoutAction();
    }
    setTimeoutAction() {
        clearTimeout(this.timeout);
        this.timeout = setTimeout(async () => {
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
            setTimeout(() => { this.bluetoothCTL.stdin.write("disconnect " + this.deviceAddress + "\n"); }, 200);
            this.isConnected = false;
            this.setTimeoutAction();
        }
    }
    bluetoothCTLDataReceived(data) {
        console.log(data);
        if (data.includes("Failed to connect")) {
            this.isBluetoothTryingToConnect = false;
        }
        else if (data.includes("Connection successful")) {
            this.isBluetoothTryingToConnect = false;
            this.isConnected = true;
            setTimeout(() => { this.bluetoothCTL.stdin.write("menu gatt\n"); }, 3000);
            setTimeout(() => { this.bluetoothCTL.stdin.write("select-attribute " + this.character + "\n"); }, 4000);
            setTimeout(() => { this.bluetoothCTL.stdin.write("notify on\n"); }, 5000);
        }
        let lines = data.split("\n");
        lines.forEach(ll => {
            let l = ll.trim().replace(/^\s+|\s+$/g, '');
            let regexMatch = l.match(this.regex);
            if (regexMatch) {
                let msg = regexMatch[regexMatch.length - 1].trim();
                if (msg[0] == "*") {
                    this.msgBuf = msg;
                }
                if (msg[0] != "*" && msg[msg.length - 1] != "!") {
                    this.msgBuf += msg;
                }
                if (msg[msg.length - 1] == "!") {
                    this.msgBuf += (msg[0] == "*") ? "" : msg;
                    let m = this.msgBuf.substring(1, this.msgBuf.length - 1);
                    this.lastMsg = m;
                    this.msgBuf = "";
                    this.lastCallIn = Date.now();
                    this.onNotifyCallback(m);
                    setTimeout(() => { this.timeoutAfterMsgToCheckForConnected(); }, this.pingInterval + 5200);
                }
            }
        });
    }
}
exports.BleConnect = BleConnect;
//# sourceMappingURL=bleconnect.js.map