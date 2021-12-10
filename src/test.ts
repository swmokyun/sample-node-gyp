var addon = require("./build/Release/native_ext.node")

const ret: string = addon.hello()
console.log(ret) // Hello World!

const ret2_1: number = addon.add()
console.log(ret2_1) // -1

const ret2_2: number = addon.add(1.1, 1.2)
console.log(ret2_2) // 2.3
