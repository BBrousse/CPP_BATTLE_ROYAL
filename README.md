# Battle royal CPP <!-- omit in toc -->
## Table of content <!-- omit in toc -->
- [1. Description](#1-description)
	- [1.1. General](#11-general)
	- [1.2. Game play](#12-game-play)
	- [1.3. Caracter types](#13-caracter-types)
	- [1.4. UI](#14-ui)
	- [1.5. Realisation](#15-realisation)
	- [1.6. Caracter carteristics](#16-caracter-carteristics)
- [2. Simplified version](#2-simplified-version)
- [Build](#build)
- [3. Classes](#3-classes)
- [4. To Do](#4-to-do)

## 1. Description

### 1.1. General 
This is a battle royal game with :
- a size configurable grid
- a configurable number of caracters
- each only 1 caracter per case
- caracter act one after an other
  
### 1.2. Game play

- Intialisation	: Caracters are randomly placed on grid
- Move : All Caracters have their own move value
- Attack : If a caracter is in attack range it attack
- Game end : Game end when only one caracter is left.

### 1.3. Caracter types
- required types are: Knight, Dwarf, Lord, Elf, Archer, Gunner, Soldier

### 1.4. UI
- Show all action during the game
- Show grid each turn

### 1.5. Realisation
- A class diagram
- The diagram will have at least three inheretance level

### 1.6. Caracter carteristics
- Caracters have their own caracteristique
  
## 2. Simplified version

The first diagram to be done will be for a implified version of the project in order to find remove issues with the most basic mechanics

It may be implemented if some difficulties with core funtions (init, attack, move ,game end) are rised

Following change may happens in this case
- grid size will be fixed
- fixed number of caracter
- caracter will not be placed randomly
- No types
- caracter carateristique will be fixed
- caracter attack range set to 1

Caracter will have the following caracteristics
- hp/max_hp :health points /max health points
- atk : attack
- mvt : movement
- rng : range
  
## Build
Build program
'''
make
'''
Clean then build program
'''
make rebuild
'''
## 3. Classes

## 4. To Do
