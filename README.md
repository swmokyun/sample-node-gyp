# sample-node-gyp

## Required

- Node.js v14
- C build tool https://github.com/nodejs/node-gyp#installation

## How to run

```
yarn
cd src
npx node-gyp configure
npx node-gyp build
npx ts-node-dev test.ts
```
