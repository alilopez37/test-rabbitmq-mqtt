const mqtt = require('mqtt')  // require mqtt

const options = {
    protocol : 'mqtt',
    port: 1883,
    username: 'guest',
    password: 'guest',
}

const client = mqtt.connect('mqtt://184.73.232.22', options)  // create a client

const topic = "esp32.mqtt"

client.on('connect', function () {
    console.log('Connected')
    client.publish(topic, 'Prueba de fuego', { qos: 0, retain: false }, (error) => {
        if (error) {
          console.error(error)
        }
        else
            console.log("Msn enviado")
      })
  })
//     client.subscribe([topic], () => {
//         console.log(`Subscribe to topic '${topic}'`)
// })

client.on ("error", (error)=> {
    console.log(error)
})
  