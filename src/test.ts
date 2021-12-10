var addon = require("./build/Release/native_ext.node")

const ret: string = addon.hello()
console.log(ret) // Hello World!

const ret2: number = addon.hello2()
console.log(ret2) // 12.34
