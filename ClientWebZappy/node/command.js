module.exports = function(info){
  var functions = require('./functions.js')(info);
  info.on("commandSend", function(commands, socket){
    var i = 0;
      console.log(commands);
      var lWorld = commands.slice(0, 3);
      switch (lWorld) {
        case "msz":
        info.emit("msz", commands.split(' '), socket);
        break;

        case "bct":
        info.emit("bct", commands.split(' '), socket);
        break;

        case "tna":
        info.emit("tna", commands.split(' '), socket);
        break;

        case "pnw":
        info.emit("pnw", commands.split(' '), socket);
        break;

        case "ppo":
        info.emit("ppo", commands.split(' '), socket);
        break;

        case "plv":
        info.emit("plv", commands.split(' '), socket);
        break;

        case "pin":
        info.emit("pin", commands.split(' '), socket);
        break;

        case "pex":
        info.emit("pex", commands.split(' '), socket);
        break;

        case "pbc":
        info.emit("pbc", commands.split(' '), socket);
        break;

        case "pfk":
        info.emit("pfk", commands.split(' '), socket);
        break;

        case "pdr":
        info.emit("pdr", commands.split(' '), socket);
        break;

        case "pgt":
        info.emit("pgt", commands.split(' '), socket);
        break;

        case "pdi":
        info.emit("pdi", commands.split(' '), socket);
        break;

        case "enw":
        info.emit("enw", commands.split(' '), socket);
        break;

        case "eht":
        info.emit("eht", commands.split(' '), socket);
        break;

        case "ebo":
        info.emit("ebo", commands.split(' '), socket);
        break;

        case "edi":
        info.emit("edi", commands.split(' '), socket);
        break;

        case "sgt":
        info.emit("sgt", commands.split(' '), socket);
        break;

        case "seg":
        info.emit("seg", commands.split(' '), socket);
        break;

        case "smg":
        info.emit("smg", commands.split(' '), socket);
        break;

        case 'pic':
        info.emit("pic", commands.split(' '), socket);
        break;

        case 'pie':
        info.emit("pie", commands.split(' '), socket);
        break;

        default:
        console.log(commands);
      };
      i++;
    //}
  });

}
