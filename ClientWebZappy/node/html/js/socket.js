var socket = io();
var time = 0;
var ask = true;
var counter = 0;
var actualInventory = 0;

socket.on('onConsole', function(string)
{
  console.log(string);
});

socket.on('teams', function(team)
{
  var html = "";
  for (var i = 0;i < team.length; i++)
  {
    html += '<li class="list-group-item"><span class="badge">' + team[i].nbPlayers + '</span>' + team[i].name + '</li>';
  }
  $('.full').html(html);
});

socket.on('toastr', function(title, description, type, time)
{
  toastr.options = {
    "closeButton": false,
    "debug": false,
    "newestOnTop": false,
    "progressBar": true,
    "positionClass": "toast-top-right",
    "preventDuplicates": false,
    "showDuration": "8000",
    "hideDuration": "1000",
    "timeOut": time,
    "extendedTimeOut": time,
    "showEasing": "swing",
    "hideEasing": "linear",
    "showMethod": "fadeIn",
    "hideMethod": "fadeOut"
  }

  toastr[type](description, title);
});

function changePlus()
{
  var id = parseInt($('#playernumber').html());
  var players = getPlayers();
  for (var i = 0;i < players.length; i++)
  {
    if (id == players[i].name)
    {
      ask = true;
      var nbr = (i + 1)%players.length;
      while (players[nbr] == 'undefined')
      {
        nbr++;
        nbr = (nbr % players.length);
      }
      socket.emit('needInventory', players[nbr].name);
    }
  }
}

function changeMinus()
{
  var id = parseInt($('#playernumber').html());
  var players = getPlayers();
  for (var i = 0;i < players.length; i++)
  {
    if (id == players[i].name)
    {
      ask = true;
      if (i == 0)
      i = players.length;
      while (players[nbr] == 'undefined')
      {
        nbr--;
        if (i == 0)
        i = players.length;
      }
      socket.emit('needInventory', players[nbr].name);
    }
  }
}

socket.on('sendInventory', function(nbPlayer, nameTeam, playerLevel, Nourriture, Linemate, Deraumere, Sibur, Mendiane, Phiras, Thystame)
{
  if (ask === true || actualInventory == nbPlayer)
  {
    ask = false;
    actualInventory = nbPlayer;
    $('#playernumber').html(nbPlayer);
    $('#teamName').html(nameTeam);
    $('#playerLevel').html(playerLevel);
    $('#Nourriture').html(Nourriture);
    $('#Linemate').html(Linemate);
    $('#Deraumere').html(Deraumere);
    $('#Sibur').html(Sibur);
    $('#Mendiane').html(Mendiane);
    $('#Phiras').html(Phiras);
    $('#Thystame').html(Thystame);
  }
});

socket.on('time', function(newTime)
{
  time = newTime;
})

socket.on('push', function(idPlayer)
{
  var character = findPlayerFromName(idPlayer);
  var x = character.x;
  var y = character.y;
  createAlert(x, y, 7, 0, 2);
});

socket.on('give', function(idPlayer, type)
{
  var character = findPlayerFromName(idPlayer);
  var x = character.x;
  var y = character.y;
  createAlert(x, y, type, 1, 2);
});

socket.on('get', function(idPlayer, type)
{
  var character = findPlayerFromName(idPlayer);
  var x = character.x;
  var y = character.y;
  createAlert(x, y, type, 0, 2);
});

socket.on('openEgg', function(nbEgg)
{
  upEgg(nbEgg);
});

socket.on('putEgg', function(nbEgg, x, y)
{
  createEgg(x, y, nbEgg);
});

socket.on('removeEgg', function(nbEgg)
{
  killEgg(nbEgg);
});

socket.on('size', function(x, y)
{
  init(x, y);
  animate();
});

socket.on('map', function(mapRessource)
{
  for (var x = 0; x < mapRessource.length; x++)
  {
    for (var y = 0; y < mapRessource[x].length; y++)
    {
      for (var i = 0; i < mapRessource[x][y].length; i++)
      {
        if (mapRessource[x][y][i].name < 7)
        {
          for (var j = 0; j < mapRessource[x][y][i].nbr; j++)
          createRessources(x, y, mapRessource[x][y][i].name);
        }
      }
    }
  }
});

socket.on('case', function(mapRessource, x, y)
{
  for (var i = 0; i < mapRessource.length; i++)
  {
    var ressource = 0;
    if (mapRessource[i].name < 7)
    {
      for (var j = 0; j < map[x][y].length; j++)
      {
        if (mapRessource[i].name == map[x][y][j].type)
        ressource += 1;
      }
      while (mapRessource[i].nbr > ressource)
      {
        createRessources(x, y, mapRessource[i].name);
        ressource += 1;
      }
      while (mapRessource[i].nbr < ressource)
      {
        removeARessource(x, y, mapRessource[i].name)
        ressource -= 1;
      }
    }
  }
})

socket.on('newPlayer', function(nb, x, y, rotate, level, team)
{
  createPlayer(x, y, level, team, nb, rotate);
});

socket.on('moove', function(nb, x, y)
{
  movePlayer(x, y, nb);
});

socket.on('rotate', function(nb, rotate)
{
  rotatePlayer(rotate, nb);
});

socket.on('levelUp', function(nb, level)
{
  upPlayer(nb, level);
});

socket.on('death', function(nb)
{
  killPlayer(nb);
})

socket.on('startIncantation', function(x, y)
{
  var players = getPlayers();
  for (var i = 0; i < players.length; i++)
  {
    if (parseInt(players[i].x) == x && parseInt(players[i].y) == y)
    {
      playerAnime(players[i].name, 'hiwave');
    }
  }
});


socket.on('endIncantation', function(x, y)
{
  var players = getPlayers();
  for (var i = 0; i < players.length; i++)
  {
    if (parseInt(players[i].x) == x && parseInt(players[i].y) == y)
    {
      playerAnime(players[i].name, 'stand');
    }
  }
});
