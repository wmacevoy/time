CFLAGS=-O3
all : context-in context uncontext unfaulty faulty mergesort-in mergesort-c Mergesort.class mergesort.jar
time : all context.time uncontext.time faulty.time unfaulty.time mergesort-c.time mergesort-java.time mergesort-kotlin.time mergesort-python.time

context-in : context-in.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)
context : context.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)
context.time : context-in context
	./context-time > context.time
uncontext : uncontext.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)
uncontext.time : uncontext
	./uncontext-time > uncontext.time
faulty : faulty.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)
faulty.time : faulty
	./faulty-time > faulty.time
unfaulty : unfaulty.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)
unfaulty.time : unfaulty
	./unfaulty-time > unfaulty.time
mergesort-in : mergesort-in.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)
mergesort : mergesort.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)
mergesort-c.time : mergesort-in mergesort
	./mergesort-time ./mergesort > mergesort-c.time
Mergesort.class : Mergesort.java
	javac Mergesort.java
mergesort-java.time : mergesort-in Mergesort.class
	./mergesort-time java Mergesort > mergesort-java.time
mergesort.jar : mergesort.kt
	kotlinc mergesort.kt -include-runtime -d mergesort.jar
mergesort-kotlin.time : mergesort-in mergesort.jar
	./mergesort-time java -jar mergesort.jar > mergesort-kotlin.time
mergesort-python.time : mergesort-in mergesort.py
	./mergesort-time ./mergesort.py > mergesort-python.time

