var countBits = function(VhodnoeChislo) {
  var ostatok;
  var DvoichnayaStroka = "";
  var kollichestvoEdinichek = 0;
  var strokaOstatoc = "";
  while(VhodnoeChislo != 0)
  {
    ostatok = VhodnoeChislo % 2;
    
    VhodnoeChislo = VhodnoeChislo / 2;

    VhodnoeChislo = Math.floor(VhodnoeChislo);
    
    strokaOstatoc = ostatok.toLocaleString();
    DvoichnayaStroka += strokaOstatoc;
    
  }
  for (var index = 0; index < DvoichnayaStroka.length; index++)
  {
    if (DvoichnayaStroka[index] == 1)
      {
        kollichestvoEdinichek++;
      }
  }
  return kollichestvoEdinichek;
}
  
console.log(countBits(123));