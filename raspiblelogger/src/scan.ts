

var cp = require('child_process');




const bluetoothCTL = cp.spawn('bluetoothctl');
bluetoothCTL.stdout.setEncoding('utf8')
bluetoothCTL.stdout.on("data", (data:any)=> dataIn(data));


let x = `24:0A:C4:FC:7D:6E
66:8B:D0:F0:C2:95
50:61:84:4C:9D:83
18:62:E4:21:83:99
1E:C4:3A:9A:C2:E0
65:C4:A7:44:0A:89
6E:A6:65:7D:58:B1
61:B3:74:4D:B2:27
79:60:4C:1B:48:F8
0D:F9:D2:08:BE:27
45:F5:0E:54:3F:81
73:77:B6:AC:FD:65
27:31:35:43:5D:5A
6C:CF:8B:9C:0D:BB
66:C4:6E:55:FF:3B
7F:E7:0B:F9:1B:54
4D:C4:B7:55:7E:97
7D:B8:F1:F0:81:E8
63:5F:3C:D6:89:C2
24:94:DA:A6:5D:08
38:DE:88:ED:EB:5D
40:CC:FB:AB:5D:41
16:8A:C0:E4:2A:29
78:05:41:07:8A:D0
76:88:1C:31:42:4E
15:4B:51:7D:64:48
42:AF:7C:DA:6A:F9
7C:B3:A8:94:0F:E4
6E:B7:EA:6E:1A:39`;

let y = x.split("\n");

let t = 10;

y.forEach(d=> {
  setTimeout(()=> {
    bluetoothCTL.stdin.write("info " + d + "\n");
  }, t); 

  t = t + 1000;
})



function dataIn(data) {
  console.log(data);
  console.log(" ");
  console.log(" ");
  console.log(" ");
  console.log(" ");
  console.log(" ");
}
