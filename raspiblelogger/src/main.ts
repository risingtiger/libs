
import { BleConnect } from "./bleconnect.js";
import * as fs from 'fs';
import * as path from 'path';
 

let configReceiverPath = '/home/pi/config_receiver.txt';
let configDispenserPath = '/home/pi/config_dispenser.txt';

if (fs.existsSync(configReceiverPath)) {
  const configReceiver = fs.readFileSync(configReceiverPath, {encoding:'utf8', flag:'r'});
  const configsReceiver = configReceiver.split("\n");
  let receiver = new BleConnect(configsReceiver[1], configsReceiver[2], Number(configsReceiver[3]), notificationReceiver);
}

if (fs.existsSync(configDispenserPath)) {
  const configDispenser = fs.readFileSync(configDispenserPath, {encoding:'utf8', flag:'r'});
  const configsDispenser = configDispenser.split("\n");
  let dispenser = new BleConnect(configsDispenser[1], configsDispenser[2], Number(configsDispenser[3]), notificationDispenser); 
}




function notificationReceiver(data:any) {
  let d = new Date();
  let dStr = d.toISOString();
  fs.appendFileSync('/home/pi/log_receiver.csv', (dStr + "," + data + "\n"));
}

function notificationDispenser(data:any) {
  let d = new Date();
  let dStr = d.toISOString();
  fs.appendFileSync('/home/pi/log_dispenser.csv', (dStr + "," + data + "\n"));
}

