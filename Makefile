
all: test_frac

test_frac: frac.o frac_int.o main.o
	$(CXX) $^ -o $@

frac.o: frac.cpp

frac_int.o: frac_int.cpp

main.o: main.cpp

.PHONY: clean
clean:
	$(RM) *.o

.PHONY: distclean
distclean: clean
	$(RM) test_frac
