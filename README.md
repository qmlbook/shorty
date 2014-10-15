Shorty
======

A QML screenshot utility.

Copyright(C) 2012-2014 Johan Thelin `<e8johan@gmail.com>`
and Juergen Bocklage-Ryannel `<juergen@ryannel.org>`

Shorty is open source software and is available under the GPLv2 license. Please
refer to the COPYING document for further details.

Introduction
------------
 
Shorty can be used to create screenshots / screenshot sequences from QML. The 
purpose is to produce screenshots or sequences of screenshots for testing and
documentation.

Building
--------

Shorty depends on Qt 5.x and uses `qmake` for building. Issue the following 
commands to build your copy of shorty:

  `qmake && make`
  
This results in the binary `bin/shorty`.

Usage
-----

Simply specify a qml-file to short. From within the qml-file, the global 
`shorty` object provides the following functions:

  - `shorty.shootFull( filename )` - grab a screenshot and save it as 
    `filename`.
  - `shorty.shoot( filename )` - grab a screenshot, scale it to 96x96 pixels
     and save it as `filename`.
  - `shorty.sendKeyPress( key )` - send a key press event for `key` to the 
     scene.
  - `shorty.sendMouseClick( x, y )` - send a left mouse button click at the 
     coordinate `x`, `y` to the scene.

Example
-------

The `example` directory contains two simple examples. `main.qml` demonstrates
how to grab screenshots. `FilmStrip.qml` is used to create filmstrips of 
sequences of screenshots (and happens to fit the `shorty.shoot()` output format
quite well.