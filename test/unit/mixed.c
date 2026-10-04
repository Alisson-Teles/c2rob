int teste(int n) { int i = 0; int j = 0; int total = 0; while (i < n) { for (j = 0; j < 3; j++) { if ((i < 2 && j < 2) || (i == 3)) { total++; } else { total += 2; } } i++; } return total; }
