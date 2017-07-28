var express      = require('express');
var app          = express();
var server       = app.listen(3000);
var io           = require('socket.io')(server);
var eventEmitter = require('events');
var event        = new eventEmitter();
var zappy        = require('./zappy.js')(event);

app.get('/game', function(req, res, next){
  var tmp = req.query;
  event.ip = tmp.ip;
  event.port = tmp.port;
  io.on('connection', function(socket){
    console.log("Connected to HtmlSocket");
    socket.emit('onConsole', "Connected to nodeJs Server !");
    zappy.connect(socket)
  })
})
app.use(express.static('html'));
