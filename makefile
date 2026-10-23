.PHONY: clean dist

dist: clean
	tar -hzcf "$(CURDIR).tar.gz" balpar/* quicksort/* string_rec/* makefile

clean:
	$(MAKE) -C balpar clean
	$(MAKE) -C quicksort clean
	$(MAKE) -C string_rec clean
