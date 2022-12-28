all: banking

banking: main.o admin.o customer.o validations.o
	gcc main.o admin.o customer.o validations.o -o banking

main.o: main.c
	gcc banking_prototype.h main.c

admin.o: admin.c
	gcc banking_prototype.h admin.c

customer.o: customer.c
	gcc banking_prototype.h customer.c

validations.o: validations.c
	gcc banking_prototype.h validations.c

clean: 
	rm *.o


