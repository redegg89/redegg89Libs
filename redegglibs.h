/*
    redegg89Libs - A C Libary for Shortcuts
    Copyright (C) 2022  redegg89

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; specifically
    version 2 of the License.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public
    License along with this library; if not, it can be found at https://www.gnu.org/licenses/old-licenses/lgpl-2.0.txt
*/
int choice;
void input(char in[]) {
    printf("%s", in);
    scanf(" %d", &choice);
    while(getchar() != '\n');
}
void clear()
{
    #ifdef _WIN32
    system("cls");
    #else
    printf("\e[1;1H\e[2J");
    #endif
}