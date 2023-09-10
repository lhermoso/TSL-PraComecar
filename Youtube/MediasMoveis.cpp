#include "pch.h"
#include "zorro.h"
#include "Risco.h"




void MediasMoveis() {

	int periodo_rapido = optimize(7, 8, 21, 3, 0);
	int period_lento = optimize(22, 22, 60, 7, 0);
	int tipo_media_rapida[5] = { MAType_EMA,MAType_SMA,MAType_TRIMA,MAType_WMA, MAType_TEMA };
	int opt_tipo_rapida = optimize(0, 0, 4, 1, 0);
	int opt_tipo_lenta = optimize(0, 0, 4, 1, 0);
	int MMI_period = optimize(0, 0, 4, 1, 0);
	double* Prices = series(price(0));

	double* media_rapida = series(MovingAverage(seriesC(), periodo_rapido, tipo_media_rapida[opt_tipo_rapida]));;
	double* media_lenta = series(MovingAverage(seriesC(), period_lento, tipo_media_rapida[opt_tipo_lenta]));;
	double* MMI_Raws = series(MMI(Prices, MMI_period));
	double* MMI_Smooths = series(LowPass(MMI_Raws, MMI_period / 1));

	if (falling(MMI_Smooths)) {
		if (crossOver(media_rapida, media_lenta))
		{
			tamanhoDoLote(1);
			enterLong();

		}

		else if (crossUnder(media_rapida, media_lenta))
		{
			tamanhoDoLote(0);
			enterShort();

		}
	}

	plot("rapida", media_rapida, LINE, RED);
	plot("lenta", media_lenta, LINE, BLUE);

}