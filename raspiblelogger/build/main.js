"use strict";
var __createBinding = (this && this.__createBinding) || (Object.create ? (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    Object.defineProperty(o, k2, { enumerable: true, get: function() { return m[k]; } });
}) : (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    o[k2] = m[k];
}));
var __setModuleDefault = (this && this.__setModuleDefault) || (Object.create ? (function(o, v) {
    Object.defineProperty(o, "default", { enumerable: true, value: v });
}) : function(o, v) {
    o["default"] = v;
});
var __importStar = (this && this.__importStar) || function (mod) {
    if (mod && mod.__esModule) return mod;
    var result = {};
    if (mod != null) for (var k in mod) if (k !== "default" && Object.prototype.hasOwnProperty.call(mod, k)) __createBinding(result, mod, k);
    __setModuleDefault(result, mod);
    return result;
};
Object.defineProperty(exports, "__esModule", { value: true });
const bleconnect_js_1 = require("./bleconnect.js");
const fs = __importStar(require("fs"));
let configReceiverPath = '/home/pi/config_receiver.txt';
let configDispenserPath = '/home/pi/config_dispenser.txt';
if (fs.existsSync(configReceiverPath)) {
    const configReceiver = fs.readFileSync(configReceiverPath, { encoding: 'utf8', flag: 'r' });
    const configsReceiver = configReceiver.split("\n");
    let receiver = new bleconnect_js_1.BleConnect(configsReceiver[1], configsReceiver[2], Number(configsReceiver[3]), notificationReceiver);
}
if (fs.existsSync(configDispenserPath)) {
    const configDispenser = fs.readFileSync(configDispenserPath, { encoding: 'utf8', flag: 'r' });
    const configsDispenser = configDispenser.split("\n");
    let dispenser = new bleconnect_js_1.BleConnect(configsDispenser[1], configsDispenser[2], Number(configsDispenser[3]), notificationDispenser);
}
function notificationReceiver(data) {
    let d = new Date();
    let dStr = d.toISOString();
    fs.appendFileSync('/home/pi/log_receiver.csv', (dStr + "," + data + "\n"));
}
function notificationDispenser(data) {
    let d = new Date();
    let dStr = d.toISOString();
    fs.appendFileSync('/home/pi/log_dispenser.csv', (dStr + "," + data + "\n"));
}
//# sourceMappingURL=main.js.map