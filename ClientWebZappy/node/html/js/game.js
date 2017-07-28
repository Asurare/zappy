var container, stats;
var camera, scene, renderer;
var clock = new THREE.Clock();
var textureLoader = new THREE.TextureLoader();
var map = [[],[]];
var players = [];
var eggs = [];
var ressourcesTextures = [];
var ressourcesSkins = [];
var ressourcesEggs = [];
var id = 1;
var updateFcts = [{}];
var lastTimeMsec = null;

//test();

function test()
{
  init();
  animate();
  for (var i = 0; i < 50; i++)
  {
    createRessources(Math.floor((Math.random() * 10)), Math.floor((Math.random() * 10)), Math.floor((Math.random() * 7)));
    //createPlayer(Math.floor((Math.random() * 10)), Math.floor((Math.random() * 10)), 3, Math.floor((Math.random() * 16)));
  }
  for (var x = 0; x < 10; x++)
  {
    for (var y = 0; y < 10; y++)
    {
      //removeAllCaseRessource(x, y);
    }
  }

  setTimeout(function()
  {
    removeARessource(3, 3, 0);
  }, 2000);

  createPlayer(8, 8, 4, 1, 1);
  setTimeout(function()
  {
    upPlayer(1, 7);
  }, 2000);
  setTimeout(function()
  {
    killPlayer(1);
  }, 4000);

  createPlayer(7, 7, 4, 8, 2);
  setTimeout(function()
  {
    upPlayer(2, 8);
  }, 2000)
  setTimeout(function()
  {
    killPlayer(2);
  }, 4000);

  createPlayer(6, 6, 4, 8, 3);
  setTimeout(function()
  {
    upPlayer(3, 1);
  }, 2000);
  createEgg(2, 2, 1);
  createEgg(2, 3, 2);
  setTimeout(function()
  {
    upEgg(1);
    createAlert(8, 8, 1, 1, 1);
    createAlert(7, 7, 7, 0, 2);
  }, 2000);


  createPlayer(5, 5, 7, 1, 99, 3);
  playerAnime(99, 'walk');
  setTimeout(function()
  {
    playerAnime(99, 'hiwave');
    setTimeout(function()
    {
      playerAnime(99, 'stand');
      setTimeout(function()
      {
        playerAnime(99, 'walk');
      }, 4000);
    }, 2000);
  }, 2000);

  createPlayer(2, 2, 7, 1, 98, 3);
  playerAnime(98, 'walk');
  setTimeout(function()
  {
    playerAnime(98, 'hiwave');
    setTimeout(function()
    {
      playerAnime(98, 'stand');
      setTimeout(function()
      {
        playerAnime(98, 'walk');
      }, 4000);
    }, 2000);
  }, 2000);

  createPlayer(3, 3, 7, 1, 97, 3);
  playerAnime(97, 'walk');
  setTimeout(function()
  {
    playerAnime(97, 'hiwave');
    setTimeout(function()
    {
      playerAnime(97, 'stand');
      setTimeout(function()
      {
        playerAnime(97, 'walk');
      }, 4000);
    }, 2000);
  }, 2000);

  createPlayer(4, 4, 7, 1, 96, 3);
  playerAnime(96, 'walk');
  setTimeout(function()
  {
    playerAnime(96, 'hiwave');
    setTimeout(function()
    {
      playerAnime(96, 'stand');
      setTimeout(function()
      {
        playerAnime(96, 'walk');
      }, 4000);
    }, 2000);
  }, 2000);
}

function initClock()
{
  if ($('#timer').text() != Math.round(clock.elapsedTime))
  $('#timer').text(Math.round(clock.elapsedTime));
}

function createBox(length, width, height, posX, posY, posZ, color, texture)
{
  //Verification
  if (typeof length == 'undefined')
  length = 100;
  if (typeof width == 'undefined')
  width = 100;
  if (typeof height == 'undefined')
  height = 100;
  if (typeof posX == 'undefined')
  posX = 0;
  if (typeof posY == 'undefined')
  posY = 0;
  if (typeof posZ == 'undefined')
  posZ = 0;
  if (typeof color == 'undefined')
  color = 0xffffff;

  var cube = new THREE.BoxGeometry(length, width, height);
  if (typeof texture != 'undefined' && texture['name'] == 'map')
  {
    var material = new THREE.MeshFaceMaterial([
      new THREE.MeshLambertMaterial({
        map: texture['side']
      }),
      new THREE.MeshLambertMaterial({
        map: texture['side']
      }),
      new THREE.MeshLambertMaterial({
        map: texture['top']
      }),
      new THREE.MeshLambertMaterial({
        map: texture['side']
      }),
      new THREE.MeshLambertMaterial({
        map: texture['side']
      }),
      new THREE.MeshLambertMaterial({
        map: texture['side']
      })
    ]);
  }
  else if (typeof texture != 'undefined')
  {
    var material = new THREE.MeshFaceMaterial([
      new THREE.MeshLambertMaterial({
        map: texture
      }),
      new THREE.MeshLambertMaterial({
        map: texture
      }),
      new THREE.MeshLambertMaterial({
        map: texture
      }),
      new THREE.MeshLambertMaterial({
        map: texture
      }),
      new THREE.MeshLambertMaterial({
        map: texture
      }),
      new THREE.MeshLambertMaterial({
        map: texture
      })
    ]);
  }
  else
  {
    var material = new THREE.MeshPhongMaterial(
      {
        color: color,
        specular: color,
        shininess: 50
      }
    );
  }
  var mesh = new THREE.Mesh( cube, material );

  mesh.name = id;
  id++;
  mesh.position.x = posX;
  mesh.position.y = posY;
  mesh.position.z = posZ;
  mesh.matrixAutoUpdate = false;
  mesh.updateMatrix();
  scene.add( mesh );
  return (mesh);
}

function createLine(beginX, beginY, beginZ, endX, endY, endZ, color)
{
  //Verification
  if (typeof beginX == 'undefined')
  beginX = 0;
  if (typeof beginY == 'undefined')
  beginY = 0;
  if (typeof beginZ == 'undefined')
  beginZ = 0;
  if (typeof endX == 'undefined')
  endX = 0;
  if (typeof endY == 'undefined')
  endY = 0;
  if (typeof endZ == 'undefined')
  endZ = 0;
  if (typeof color == 'undefined')
  color = 0xFFFFFF;


  var material = new THREE.LineBasicMaterial(
    {
      color: color
    }
  );

  var geometry = new THREE.Geometry();
  geometry.vertices.push(
    new THREE.Vector3( beginX, beginY, beginZ ),
    new THREE.Vector3( endX, endY, endZ )
  );

  var line = new THREE.Line( geometry, material );
  line.name = id;
  id++;
  scene.add( line );
  return (line);
}

function createSphere(ray, posX, posY, posZ, texture)
{
  //Verification
  if (typeof ray == 'undefined')
  ray = 10;
  if (typeof posX == 'undefined')
  posX = 0;
  if (typeof posY == 'undefined')
  posY = 0;
  if (typeof posZ == 'undefined')
  posZ = 0;

  var geometry = new THREE.SphereGeometry(ray * 2, 50, 50);

  var material = new THREE.MeshPhongMaterial();
  if (typeof texture != 'undefined')
  material.map = texture;
  var mesh = new THREE.Mesh(geometry, material);
  mesh.position.x = posX;
  mesh.position.y = posY;
  mesh.position.z = posZ;
  scene.add(mesh);
  return (mesh);
}

//alert 0 = moins / alert 1 = plus / alert 3 = TNT
function createAlert(x, y, ressource, alert, time)
{
  var side = 50;
  var h = 260;
  posX = (-100 * getMaxXMap() / 2) + x * 100 + 50;
  posY = (-100 * getMaxYMap() / 2) + y * 100 + 50;
  var colorCube = [
    0x00FF00,
    0xffff00,
    0xff00ff,
    0x0044ff,
    0x000089,
    0x900000,
    0x000000,
  ];
  var box = createBox(side, side, side, posX, 50 + h, posY, colorCube[ressource], ressourcesTextures[alert + 1][ressource]);
  var line = createLine(posX, 50, posY, posX, 50 + h, posY, 0x900000);
  setTimeout(function()
  {
    removeEntity(box.id);
    removeEntity(line.id);
  }, 1000 * time);
}

function initEggsSkins()
{
  ressourcesEggs =
  [
    textureLoader.load('./src/eggs/green.png'),
    textureLoader.load('./src/eggs/blue.png'),
  ];
}

function findEggFromName(name)
{
  for (var i = 0; i < eggs.length; i++)
  {
    if (eggs[i].name == name)
    return (eggs[i]);
  }
  console.log("ERROR : egg not found.");
}

function killEgg(name)
{
  for (var i = 0; i < eggs.length; i++)
  {
    if (eggs[i].name == name)
    {
      removeEntity(eggs[i].id);
      eggs.splice(i, 1);
      return;
    }
  }
}

function upEgg(name)
{
  for (var i = 0; i < eggs.length; i++)
  {
    if (eggs[i].name == name)
    {
      eggs[i].egg.material.map = ressourcesEggs[1];
      return;
    }
  }
}

function createEgg(x, y, name)
{
  var ray = 8;
  posX = (-100 * getMaxXMap() / 2) + x * 100 + Math.floor((Math.random() * 60) + 20);
  posY = (-100 * getMaxYMap() / 2) + y * 100 + Math.floor((Math.random() * 60) + 20);
  var egg = createSphere(ray, posX, 50 + ray * 2, posY, ressourcesEggs[0]);
  var object = {id: egg.id, x: x, y: y, name: name, egg: egg};
  eggs.push(object);
}

function findPlayerFromName(name)
{
  for (var i = 0; i < players.length; i++)
  {
    if (players[i].name == name)
    return (players[i]);
  }
  console.log("ERROR : player not found.");
}

function killPlayer(name)
{
  character = findPlayerFromName(name);
  removeEntity(character.player.root.id);
  for (var i = 0; i <= players.length; i++)
  {
    if (players[i].name == character.name)
    {
      players.splice(i, 1);
      return;
    }
  }
}

function upPlayer(name, lvl)
{
  character = findPlayerFromName(name);
  killPlayer(name);
  createPlayer(character.x, character.y, lvl, character.team, character.name, character.rotation);
}

function movePlayer(x, y, name)
{
  character = findPlayerFromName(name);
  posX = (-100 * getMaxXMap() / 2) + x * 100 + Math.floor((Math.random() * 60) + 20);
  posZ = (-100 * getMaxYMap() / 2) + y * 100 + Math.floor((Math.random() * 60) + 20);
  character.player.root.position.z = posZ;
  character.player.root.position.x = posX;
  character.x = x;
  character.y = y;
}

function rotatePlayer(rotate, name)
{
  character = findPlayerFromName(name);
  if (rotate == 1)
  character.player.root.rotation.y = Math.PI;
  else if (rotate == 2)
  character.player.root.rotation.y = Math.PI / 2;
  else if (rotate == 3)
  character.player.root.rotation.y = 0;
  else if (rotate == 4)
  character.player.root.rotation.y = 3 * Math.PI / 2;
  else
  character.player.root.rotation.y = Math.PI;
}

function initPlayerSkins()
{
  ressourcesSkins =
  [
    textureLoader.load('./src/skins/3djesus.png'),
    textureLoader.load('./src/skins/agentsmith.png'),
    textureLoader.load('./src/skins/batman.png'),
    textureLoader.load('./src/skins/char.png'),
    textureLoader.load('./src/skins/god.png'),
    textureLoader.load('./src/skins/Iron-Man-Minecraft-Skin.png'),
    textureLoader.load('./src/skins/jetienne.png'),
    textureLoader.load('./src/skins/Joker.png'),
    textureLoader.load('./src/skins/Mario.png'),
    textureLoader.load('./src/skins/martialartist.png'),
    textureLoader.load('./src/skins/robocop.png'),
    textureLoader.load('./src/skins/Sonicthehedgehog.png'),
    textureLoader.load('./src/skins/Spiderman.png'),
    textureLoader.load('./src/skins/Superman.png'),
    textureLoader.load('./src/skins/theflash.png'),
    textureLoader.load('./src/skins/woody.png'),
  ];
}

function getPlayers()
{
  return (players);
}

function playerAnime(name, anime)
{
  console.log(2);
  var character = findPlayerFromName(name);
  console.log(1);
  if (character.anime == 1)
  {

    for (var i = 0; i < updateFcts.length; i++)
    {
      if (character.name == updateFcts[i].id)
      {
        updateFcts.splice(i, 1);
      }
    }
  }
  // init bodyAnims
  var bodyAnims	= new THREEx.createMinecraftCharBodyAnimations(character.player);
  bodyAnims.start(anime);
  var newUp = { func: function(delta, now){
    bodyAnims.update(delta, now);
  }, id: character.name, anime: anime };
  updateFcts.push(newUp);
  var switchBodyValue	= function(anime){
    bodyAnims.start(anime);
  };
  requestAnimationFrame(function animate(nowMsec)
  {
    if (updateFcts.length == 1)
    return;
    // keep looping
    requestAnimationFrame( animate );
    // measure time
    lastTimeMsec	= lastTimeMsec || nowMsec-1000/60;
    var deltaMsec	= Math.min(200, nowMsec - lastTimeMsec);
    lastTimeMsec	= nowMsec;
    // call each update function
    for (var i = 1; i < updateFcts.length; i++)
    updateFcts[i].func(deltaMsec/1000, nowMsec/1000);
  });
  character.anime = 1;
  if (anime == 'stand')
  {
    setTimeout(function(){
      updateFcts.splice(updateFcts.length - 1, 1);
      character.anime = 0;
    }, 2000);
  }
}

function createPlayer(x, y, lvl, team, name, rotation)
{
  if (typeof findPlayerFromName(name) != 'undefined')
  return;
  if (typeof lvl == 'undefined' || lvl < 1)
  lvl = 1;
  posX = (-100 * getMaxXMap() / 2) + x * 100 + Math.floor((Math.random() * 60) + 20);
  posZ = (-100 * getMaxYMap() / 2) + y * 100 + Math.floor((Math.random() * 60) + 20);
  size = 32 * lvl;
  if (typeof rotation == 'undefined')
  rotation = 3;

  var character	= new THREEx.MinecraftChar(ressourcesSkins[team % ressourcesSkins.length], size);
  character.root.name = id;
  character.root.position.y = 50;
  character.root.position.x = posX;
  character.root.position.z = posZ;
  scene.add(character.root);
  var object = {id: character.root.id, name: name, rotation: rotation, lvl: lvl, team: team, player: character, x: x, y: y, anime: 0};
  players.push(object);
  rotatePlayer(rotation, name);
}

function createRessources(x, y, ressource)
{
  var side = 15;
  posX = (-100 * getMaxXMap() / 2) + x * 100 + Math.floor((Math.random() * 60) + 20);
  posY = (-100 * getMaxYMap() / 2) + y * 100 + Math.floor((Math.random() * 60) + 20);
  var colorCube = [
    0x00FF00,
    0xffff00,
    0xff00ff,
    0x0044ff,
    0x000089,
    0x900000,
    0x000000,
  ];
  var box = createBox(side, side, side, posX, 50 + side / 2 , posY ,colorCube[ressource], ressourcesTextures[0][ressource]);
  var object = {type: ressource, id: box.id};
  map[x][y].push(object);
}

function initTextures()
{
  ressourcesTextures =
  [
    [
      textureLoader.load('./src/ressources/normal/melon.png'),
      textureLoader.load('./src/ressources/normal/wood.png'),
      textureLoader.load('./src/ressources/normal/emerald.jpg'),
      textureLoader.load('./src/ressources/normal/gold.png'),
      textureLoader.load('./src/ressources/normal/iron.png'),
      textureLoader.load('./src/ressources/normal/redstone.jpg'),
      textureLoader.load('./src/ressources/normal/lapis.png')
    ],
    [
      textureLoader.load('./src/ressources/moins/melon.png'),
      textureLoader.load('./src/ressources/moins/wood.png'),
      textureLoader.load('./src/ressources/moins/emerald.jpg'),
      textureLoader.load('./src/ressources/moins/gold.png'),
      textureLoader.load('./src/ressources/moins/iron.png'),
      textureLoader.load('./src/ressources/moins/redstone.jpg'),
      textureLoader.load('./src/ressources/moins/lapis.png'),
      textureLoader.load('./src/ressources/moins/tnt.jpg')
    ],
    [
      textureLoader.load('./src/ressources/plus/melon.png'),
      textureLoader.load('./src/ressources/plus/wood.png'),
      textureLoader.load('./src/ressources/plus/emerald.jpg'),
      textureLoader.load('./src/ressources/plus/gold.png'),
      textureLoader.load('./src/ressources/plus/iron.png'),
      textureLoader.load('./src/ressources/plus/redstone.jpg'),
      textureLoader.load('./src/ressources/plus/lapis.png')
    ],
  ];
}

function removeAllCaseRessource(x, y)
{
  while (map[x][y].length > 0)
  {
    removeEntity(map[x][y][0].id);
    map[x][y].splice(0, 1);
  }
}

function removeARessource(x, y, ressource)
{
  for (var i = 0; i < map[x][y].length; i++)
  {
    if (map[x][y][i].type == ressource)
    {
      removeEntity(map[x][y][i].id);
      map[x][y].splice(i, 1);
      return;
    }
  }
}

function removeEntity(objectId)
{
  var selectedObject = scene.getObjectById(objectId);
  scene.remove( selectedObject );
}

function getMaxXMap()
{
  return (map.length);
}

function getMaxYMap()
{
  return (map[0].length);
}

function initCamera()
{
  camera = new THREE.PerspectiveCamera( 60, window.innerWidth / window.innerHeight, 100, 2000000  );
  camera.position.y = 1000;
  camera.position.z = 1000;
  camera.rotation.x = -0.8;
  controls = new THREE.FlyControls( camera );
  controls.movementSpeed = 500;
  controls.domElement = container;
  controls.rollSpeed = Math.PI / 10;
  controls.autoForward = false;
  controls.dragToLook = false;
}

function initScene()
{
  scene = new THREE.Scene();
  scene.fog = new THREE.Fog( 0x000000, 3500, 15000 );
  scene.fog.color.setHSL( 0.51, 0.4, 0.01 );
}

function initMap(mapX, mapY)
{
  var nbrYLines = 0;
  if (typeof mapX == 'undefined')
  mapX = 10;
  if (typeof mapY == 'undefined')
  mapY = 10;
  var mapSide = textureLoader.load('./src/ressources/grassSide.jpg');
  var mapTop = textureLoader.load('./src/ressources/grassTop.jpg');
  var texture = {name: 'map', top: mapTop, side: mapSide};
  for ( var x = (-100 * mapX / 2) + 50; x < (100 * mapX / 2); x += 100 )
  {
    for ( var y = (-100 * mapY / 2) + 50; y < (100 * mapY / 2); y += 100 )
    {
      createBox(100, 100, 100, x, 0, y, 0xffffff, texture);
    }
  }
  for (var x = 0; x < mapX; x++)
  {
    map[x] = [];
    for (var y = 0; y < mapY; y++)
    {
      map[x][y] = [];
    }
  }
}

function initSky2()
{
  var dirLight = new THREE.DirectionalLight( 0xffffff, 0.05 );
  dirLight.position.set( 0, -1, 0 ).normalize();
  scene.add( dirLight );
  dirLight.color.setHSL( 0.1, 0.7, 0.5 );
}

function addLight( h, s, l, x, y, z, star )
{
  var light = new THREE.PointLight( 0xffffff, 1, 10000000 );
  light.color.setHSL( h, s, l );
  light.position.set( x, y, z );
  scene.add( light );
  if (star == 1)
  {
    var textureFlare0 = textureLoader.load( "textures/lensflare0.png" );
    var textureFlare2 = textureLoader.load( "textures/lensflare2.png" );
    var textureFlare3 = textureLoader.load( "textures/lensflare3.png" );

    var flareColor = new THREE.Color( 0xffffff );
    flareColor.setHSL( h, s, l + 0.5 );
    var lensFlare = new THREE.LensFlare( textureFlare0, 700, 0.0, THREE.AdditiveBlending, flareColor );
    lensFlare.add( textureFlare2, 512, 0.0, THREE.AdditiveBlending );
    lensFlare.add( textureFlare2, 512, 0.0, THREE.AdditiveBlending );
    lensFlare.add( textureFlare2, 512, 0.0, THREE.AdditiveBlending );
    lensFlare.add( textureFlare3, 60, 0.6, THREE.AdditiveBlending );
    lensFlare.add( textureFlare3, 70, 0.7, THREE.AdditiveBlending );
    lensFlare.add( textureFlare3, 120, 0.9, THREE.AdditiveBlending );
    lensFlare.add( textureFlare3, 70, 1.0, THREE.AdditiveBlending );
    lensFlare.customUpdateCallback = lensFlareUpdateCallback;
    lensFlare.position.copy( light.position );
    scene.add( lensFlare );
  }
}

function init(mapX, mapY)
{
  container = document.createElement( 'div' );
  document.body.appendChild( container );

  initClock();
  initCamera();
  initScene();
  initTextures();
  initPlayerSkins();
  initEggsSkins();
  initMap(mapX, mapY);
  addLight(1, 1, 1, 0, 5000, 0, 1);
  addLight(1, 1, 1, -5000, 5000, -5000, 0);
  addLight(1, 1, 1, 5000, 5000, 5000, 0);

  /* If need this is a helper
  var helper = new THREE.GridHelper( 5000, 5000, 0xffffff, 0xffffff );
  scene.add( helper );*/

  // renderer
  renderer = new THREE.WebGLRenderer( { antialias: true, alpha: true } );
  renderer.setClearColor( scene.fog.color );
  renderer.setPixelRatio( window.devicePixelRatio );
  renderer.setSize( window.innerWidth, window.innerHeight );
  container.appendChild( renderer.domElement );

  //
  renderer.gammaInput = true;
  renderer.gammaOutput = true;

  initSky();

  // events
  window.addEventListener( 'resize', onWindowResize, false );
}

function lensFlareUpdateCallback( object )
{
  var f, fl = object.lensFlares.length;
  var flare;
  var vecX = -object.positionScreen.x * 2;
  var vecY = -object.positionScreen.y * 2;
  for( f = 0; f < fl; f++ ) {
    flare = object.lensFlares[ f ];
    flare.x = object.positionScreen.x + vecX * flare.distance;
    flare.y = object.positionScreen.y + vecY * flare.distance;
    flare.rotation = 0;
  }
  object.lensFlares[ 2 ].y += 0.025;
  object.lensFlares[ 3 ].rotation = object.positionScreen.x * 0.5 + THREE.Math.degToRad( 45 );
}

function onWindowResize( event )
{
  renderer.setSize( window.innerWidth, window.innerHeight );
  camera.aspect = window.innerWidth / window.innerHeight;
  camera.updateProjectionMatrix();
}

function animate()
{
  requestAnimationFrame( animate );
  render();
}

function render()
{
  var delta = clock.getDelta();
  controls.update( delta );
  renderer.render( scene, camera );
  initClock();
}

function initSky()
{
  // Add Sky Mesh
  sky = new THREE.Sky();
  scene.add( sky.mesh );
  // Add Sun Helper
  sunSphere = new THREE.Mesh(
    new THREE.SphereBufferGeometry( 20000, 16, 8 ),
    new THREE.MeshBasicMaterial( { color: 0xffffff } )
  );
  sunSphere.position.y = - 700000;
  sunSphere.visible = false;
  scene.add( sunSphere );
  /// GUI
  var effectController  = {
    turbidity: 10,
    reileigh: 2,
    mieCoefficient: 0.005,
    mieDirectionalG: 0.8,
    luminance: 1,
    inclination: 0, // elevation / inclination
    azimuth: 0.25, // Facing front,
    sun: ! true
  };
  var distance = 400000;
  function guiChanged() {
    var uniforms = sky.uniforms;
    uniforms.turbidity.value = effectController.turbidity;
    uniforms.reileigh.value = effectController.reileigh;
    uniforms.luminance.value = effectController.luminance;
    uniforms.mieCoefficient.value = effectController.mieCoefficient;
    uniforms.mieDirectionalG.value = effectController.mieDirectionalG;
    var theta = Math.PI * ( effectController.inclination - 0.5 );
    var phi = 2 * Math.PI * ( effectController.azimuth - 0.5 );
    sunSphere.position.x = distance * Math.cos( phi );
    sunSphere.position.y = distance * Math.sin( phi ) * Math.sin( theta );
    sunSphere.position.z = distance * Math.sin( phi ) * Math.cos( theta );
    sunSphere.visible = effectController.sun;
    sky.uniforms.sunPosition.value.copy( sunSphere.position );
    renderer.render( scene, camera );
  }
  /*
  var gui = new dat.GUI();
  gui.add( effectController, "turbidity", 1.0, 20.0, 0.1 ).onChange( guiChanged );
  gui.add( effectController, "reileigh", 0.0, 4, 0.001 ).onChange( guiChanged );
  gui.add( effectController, "mieCoefficient", 0.0, 0.1, 0.001 ).onChange( guiChanged );
  gui.add( effectController, "mieDirectionalG", 0.0, 1, 0.001 ).onChange( guiChanged );
  gui.add( effectController, "luminance", 0.0, 2 ).onChange( guiChanged );
  gui.add( effectController, "inclination", 0, 1, 0.0001 ).onChange( guiChanged );
  gui.add( effectController, "azimuth", 0, 1, 0.0001 ).onChange( guiChanged );
  gui.add( effectController, "sun" ).onChange( guiChanged );
  */
  guiChanged();
}
