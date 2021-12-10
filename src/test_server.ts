import { Static, Type } from "@sinclair/typebox"
import fastify, { FastifyInstance } from "fastify"
import fastifySwagger from "fastify-swagger"

var addon = require("./build/Release/native_ext.node")

const PORT = 9000

const server: FastifyInstance = fastify({ logger: true })

server.register(fastifySwagger, {
  routePrefix: "/docs",
  exposeRoute: true,
})

const Param = Type.Object({
  p1: Type.Number(),
  p2: Type.Number(),
})
type ParamType = Static<typeof Param>

const Response = Type.Number()
type ResponseType = Static<typeof Response>

server.get<{ Querystring: ParamType; Reply: ResponseType }>(
  "/test_add",
  {
    schema: {
      querystring: Param,
      response: {
        200: Response,
      },
    },
  },
  async (req, rep) => {
    const { query: param } = req

    const ret: number = addon.add(param.p1, param.p2)

    rep.status(200).send(ret)
  }
)

server.listen(PORT)
