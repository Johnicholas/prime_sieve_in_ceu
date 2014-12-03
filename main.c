#include <stdio.h>

#include "_ceu_app.c"

extern void ceu_app_init (tceu_app* app);

int main (int argc, char *argv[])
{
	byte CEU_DATA[sizeof(CEU_Main)];
	tceu_app app;
	int i;

	app.data = (tceu_org*) &CEU_DATA;
        app.init = &ceu_app_init;

	app.init(&app);
	for (i = 2; i < 10000; i += 1) {
		ceu_sys_go(&app, CEU_IN_NUMBER, (tceu_evtp)i);
	}
	return 0;
}
