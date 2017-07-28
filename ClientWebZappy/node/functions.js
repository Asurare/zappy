var map = null;
var team = [];
var nbTeam = 0;
var nbCase = 0;
var nbCheck = 0;
var time = 0;

module.exports = function(info){
  info.on('msz', function(command, socket){
    map = [];
    for (var x = 0; x < parseInt(command[1]); x++)
    {
      map[x] = [];
      for (var y = 0; y  < parseInt(command[2]); y++)
      {
        map[x][y] = [];
      }
    }
    nbCase = parseInt(command[1]) * parseInt(command[2]);
    console.log("Map created : " + command[1] + "," + command[2]);
    socket.emit('size', parseInt(command[1]), parseInt(command[2]));
  })
  info.on('bct', function(command, socket){
    var i = 0;
    var nb = 3;
    var object;
    nbCheck++;
    map[parseInt(command[1])][parseInt(command[2])] = map[parseInt(command[1])][parseInt(command[2])].filter(e => e.name >= 7);
    while (i < 7){
      object = {name: i, nbr: parseInt(command[nb])};
      map[parseInt(command[1])][parseInt(command[2])].push(object);
      i++;
      nb++;
    }
    if (nbCheck == nbCase)
    {
      socket.emit('map', map);
    }
    if (nbCheck > nbCase)
    {
      socket.emit('case', map[parseInt(command[1])][parseInt(command[2])], parseInt(command[1]), parseInt(command[2]));
    }
    console.log('Case updated on:' + command[1] + ',' + command[2]);
  })
  info.on('tna', function(command, socket){
    command[1] = command[1].replace(/(\r\n|\n|\r)/gm,"");
    var object = {id: nbTeam, name: command[1], nbPlayers: 0};
    team.push(object);
    nbTeam++;
    console.log("Nombre d'équipes : " + nbTeam);
    console.log(team);
    socket.emit('teams', team);
  })
  info.on('pnw', function(command, socket){
    command[6] = command[6].replace(/(\r\n|\n|\r)/gm,"");
    var i = 0;
    while (team[i].name != command[6])
    i++;
    team[i].nbPlayers++;
    var object = {name: 7, nbr: parseInt(command[1]), Level: parseInt(command[5]), Team: command[6]};
    map[parseInt(command[2])][parseInt(command[3])].push(object);
    console.log("New Player on " + command[2] + "," + command[3] + "!");
    socket.emit('newPlayer', parseInt(command[1]), parseInt(command[2]), parseInt(command[3]), parseInt(command[4]), command[5], i);
    socket.emit('toastr', "Message from the server", "Player " + command[1] + " enter the game, in " + command[6] + "'s team.'", "info", 5000);
    socket.emit('teams', team);
  })
  info.on('ppo', function(command, socket){
    for (var x = 0; x < map.length; x++){
      for (var y = 0; y < map[x].length; y++){
        for (var i = 0; i < map[x][y].length; i++){

          if (map[x][y][i].nbr == parseInt(command[1]) && map[x][y][i].name == 7){
            var myPlayer = map[x][y][i];
            map[x][y] = map[x][y].filter(e => e !== myPlayer)
            map[parseInt(command[2])][parseInt(command[3])].push(myPlayer);
            console.log("Player " + command[1] + " moved " + command[2] + "," + command[3] + " with orientation: " + command[4]);
            socket.emit('rotate', parseInt(command[1]) ,parseInt(command[4]));
            socket.emit('moove', parseInt(command[1]), command[2], command[3]);
          }
        }
      }
    }

  })
  info.on('plv', function(command, socket){
    for (var x = 0; x < map.length; x++){
      for (var y = 0; y < map[x].length; y++){
        for (var i = 0; i < map[x][y].length; i++){
          if (map[x][y][i].name == 7)
          console.log(map[x][y][i]);
          if (map[x][y][i].nbr == parseInt(command[1]) && map[x][y][i].name == 7){
            map[x][y][i].Level = parseInt(command[2]);
            console.log(map[x][y][i]);
            console.log("Level Up of player " + command[1]);
            socket.emit('levelUp', parseInt(command[1]), parseInt(command[2]))
            socket.emit('toastr', "Message from the server", "Player " + command[1] + " up on level " + command[2] + " !", "success", 10000);
          }
        }
      }
    }
  })
  info.on('pin', function(command, socket){
    console.log('Inventory is sent');
    for (var x = 0; x < map.length; x++){
      for (var y = 0; y < map[x].length; y++){
        for (var i = 0; i < map[x][y].length; i++){
          if (map[x][y][i].nbr == parseInt(command[1]) && map[x][y][i].name == 7){
            socket.emit('sendInventory', map[x][y][i].nbr, map[x][y][i].Team, map[x][y][i].Level , parseInt(command[4]), parseInt(command[5]), parseInt(command[6]), parseInt(command[7]), parseInt(command[8]), parseInt(command[9]), parseInt(command[10]))
          }
        }
      }
    }
  })
  info.on('pex', function(command, socket){
    console.log("Player " + command[1] + " pushed all the other players in his case");
    socket.emit('push', parseInt(command[1]));
  })
  info.on('pfk', function(command, socket){
    console.log("Player " + command[1] + " gave an egg !");
  })
  info.on('pdr', function(command, socket){
    console.log("Player " + command[1] + " drop a ressource (type :" + command[2] + ")");
    socket.emit('give', parseInt(command[1]), parseInt(command[2]));
  })
  info.on('pgt', function(command, socket){
    console.log("Player " + command[1] + " loot a ressource (type :" + command[2] + ")");
    socket.emit('get', parseInt(command[1]), parseInt(command[2]));
  })
  info.on('pdi', function(command, socket){
    command[1] = command[1].replace(/(\r\n|\n|\r)/gm,"");
    for (let x in map){
      for (let y in map[x]){
        for (let i in map[x][y])
        {
          if (map[x][y][i].name == 7 && map[x][y][i].nbr == parseInt(command[1]))
          for (let nb in team)
          if (team[nb].name == map[x][y][i].Team)
          team[nb].nbPlayers -= 1;
        }
        map[x][y] = map[x][y].filter(e => e.nb !== parseInt(command[1]));
      }
    }
    console.log("Player " + command[1] + " died");
    socket.emit('death', parseInt(command[1]));
    socket.emit('teams', team);
    socket.emit('toastr', "Message from the server", "Player " + command[1] + " died", "error", 5000);
  })
  info.on('enw', function(command, socket){
    console.log('enw is made with: ' + command);
    socket.emit('putEgg', parseInt(command[1]), parseInt(command[3]), parseInt(command[4]));
  })
  info.on('eht', function(command, socket){
    console.log("Egg " + command[1] + " is open !");
    socket.emit('openEgg', parseInt(command[1]));
  })
  info.on('ebo', function(command, socket){
    console.log("Player connected on the egg " + command[1] + " !");
    socket.emit('removeEgg', parseInt(command[1]));
  })
  info.on('edi', function(command, socket){
    console.log("Egg " + command[1] + "is dead");
    socket.emit('removeEgg', parseInt(command[1]));
  })
  info.on('sgt', function(command, socket){
    time = parseInt(command[1]);
    console.log("Time on server " + command[1]);
    socket.emit('time', parseInt(command[1]));
    socket.emit('toastr', "Message from the server", "Time set at " + command[1], "info", 5000);
  })
  info.on('seg', function(command, socket){
    console.log("End of the game : team " + command[1] + " win !");
    socket.emit('toastr', "Message from the server", "End of the game : team " + command[1] + " win !", "success", 10000);
  })
  info.on('smg', function(command, socket){
    console.log("Message from the server: " + command[1]);
    socket.emit('toastr', "Message from the server", command[1], "info", 5000);
  })
  info.on('pbc', function(command, socket){
    for (var i = 2; i < command.length; i++)
    command[2] = command[2] + " " + command[i];
    command[2] = command[2].replace("\n","");
    console.log("Message from player: " + command[1]);
    //socket.emit('toastr', "Message from player " + command[1], command[2], "info", 5000);
  })
  info.on('pic', function(command, socket){
    console.log("Incantation in: " + command[1] + ";" + command[2] + " started");
    socket.emit('startIncantation', parseInt(command[1]), parseInt(command[2]));
    socket.emit('toastr', "Incantation from player " + command[4] + " !", command[1] + "," + command[2], "info", 3000);
  })
  info.on('pie', function(command, socket){
    console.log("Incantation in: " + command[1] + ";" + command[2] + " ended");
    socket.emit('endIncantation', command[1], command[2]);
  })

}
