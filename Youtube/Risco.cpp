#include "pch.h"
#include "zorro.h"



void tamanhoDoLote(int Compra)
{

	double capital = Capital * sqrt(1 + (ProfitClosed / Capital));

	double capitalPorAtivo = capital / sqrt(NumAssetsUsed);
	double margin = (Compra ? OptimalFLong : OptimalFShort) * capitalPorAtivo;

	if (margin >= 0)
	{
		Margin = margin;

	}
	else {

		Lots = 0;
		Margin = 0;
	}
		

	





}