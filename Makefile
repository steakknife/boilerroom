include/config.h: has/*.c
	scripts/has2config_h > $@

test: check

check: include/config.h test/*.c
	scripts/check

clean: 
	rm -f include/config.h
