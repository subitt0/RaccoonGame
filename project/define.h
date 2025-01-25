#pragma once
#ifndef DEFINE_H
#define DEFINE_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <conio.h>
#include <windows.h>

#define WIDTH 26
#define HEIGHT 22


#define BLACK 0
#define BLUE1 1
#define GREEN1 2
#define CYAN1 3
#define RED1 4
#define MAGENTA1 5
#define YELLOW1 6
#define GRAY1 7
#define GRAY2 8
#define BLUE2 9
#define GREEN2 10
#define CYAN2 11
#define RED2 12
#define MAGENTA2 13
#define YELLOW2 14
#define WHITE 15


#define PLAYER "��"
#define BLANK "  "
#define ENEMY "��"

#define ESC 0x1b

#define SPECIAL1 0xe0 // Ư��Ű�� 0xe0 + key ������ �����ȴ�.
#define SPECIAL2 0x00 // keypad ��� 0x00 + key �� �����ȴ�.

#define UP  0x48 // Up key�� 0xe0 + 0x48 �ΰ��� ���� ���´�.
#define DOWN 0x50
#define LEFT 0x4b
#define RIGHT 0x4d
#define SPACE 32
#define ENTER 0x0D

#define UP2		'w'
#define DOWN2	's'
#define LEFT2	'a'
#define RIGHT2	'd'

#define MAPX 3
#define MAPY 3

#endif
