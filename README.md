# buyItem
### function to buy item in shops 

This program assume the situation when you go to shopping and buy item in each shop.<br>
The shops arrange in circular order. <br>
Each shop has open time and close time. <br>
you could buy item if you got shop in time and buy only one item in each shop. <br>
amount of time you use to go to the next shop is walk time. you will shop untill you can not buy any item.<br>

**Rule:** <br>
* openAt is an array and has number of element in range 2-50 <br>
* number of element of closeAt have to equal openAt <br>
* walkTime value have to is in range 1-1000000 <br>
* value of each element in openAt is in range 0-999999 <br>
* value of each element in closeAt is in range openAt[i]+1 - 1000000 <br>
</p>

**Compile**
```
gcc -o buyItem buyItem.c
```
**Run**
```
./buyItem
```

