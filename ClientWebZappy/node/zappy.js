module.exports = function(info){

  return {
    connect(socket){
      var net = require('net');
      var command = require('./command.js')(info);
      var splitStream = require('split-stream');

      var split = splitStream.create();
      var client = new net.Socket();
      client.connect(info.port, info.ip, function() {
        console.log('Connected');
        socket.emit('toastr', "Bienvenue", "Tous à vos pioches !", "success", 10000);
      });

      split.on('data', function(data) {
        if (data == "BIENVENUE")
        client.write("GRAPHIC\n");
        else
        info.emit("commandSend", data, socket);
      });
      client.pipe(split);

      socket.on('needInventory', function(idPlayer){
        client.write("pin " + idPlayer + "\n");
      });


      process.stdin.on('data', function(command){
        if (command == "exit\n")
        {
          client.end();
        }
        else {
          client.write(command);
        }
      });

      client.on('close', function() {
        console.log('Connection closed');
        socket.emit('toastr', "Connection", "Connection closed", "error", 10000);
      });

      client.on('error', function(err){
        console.log("Can\'t reach the server.. Is it opened ?");
        socket.emit('toastr', "Connection", "Can\'t reach the server.. Is it opened ?", "error", 10000);
      })
    }
  }
}
