
cc = g++
cflags = -Wall -pedantic -O3 -std=c++20 -fsanitize=address

objects = main.o test.o mytest.o container.o exc1as.o exc1af.o exc1bs.o exc1bf.o exc2as.o exc2af.o exc2bs.o exc2bf.o exc3f.o exc3s.o test1a.o test1b.o test2a.o test2b.o test3.o

libcon = container/container.hpp container/testable.hpp container/traversable.cpp container/traversable.hpp container/mappable.cpp container/mappable.hpp container/dictionary.cpp container/dictionary.hpp container/linear.cpp container/linear.hpp

libexc = $(libcon) zlasdtest/container/container.hpp zlasdtest/container/testable.hpp zlasdtest/container/traversable.hpp zlasdtest/container/mappable.hpp zlasdtest/container/dictionary.hpp zlasdtest/container/linear.hpp

libexc1a = $(libexc) vector/vector.cpp vector/vector.hpp list/list.cpp list/list.hpp

libexc1b = $(libexc1a) stack/stack.hpp stack/lst/stacklst.cpp stack/lst/stacklst.hpp stack/vec/stackvec.cpp stack/vec/stackvec.hpp queue/queue.hpp queue/lst/queuelst.cpp queue/lst/queuelst.hpp queue/vec/queuevec.cpp queue/vec/queuevec.hpp

libexc2a = $(libexc) iterator/iterator.hpp binarytree/binarytree.cpp binarytree/binarytree.hpp binarytree/lnk/binarytreelnk.cpp binarytree/lnk/binarytreelnk.hpp binarytree/vec/binarytreevec.cpp binarytree/vec/binarytreevec.hpp

libexc2b = $(libexc2a) bst/bst.cpp bst/bst.hpp

libexc3 = $(libexc) hashtable/hashtable.cpp hashtable/hashtable.hpp hashtable/clsadr/htclsadr.cpp hashtable/clsadr/htclsadr.hpp hashtable/opnadr/htopnadr.cpp hashtable/opnadr/htopnadr.hpp

libtest1a = $(libcon) vector/vector.cpp vector/vector.hpp list/list.cpp list/list.hpp

libtest1b = $(libtest1a) stack/stack.hpp stack/lst/stacklst.cpp stack/lst/stacklst.hpp stack/vec/stackvec.cpp stack/vec/stackvec.hpp queue/queue.hpp queue/lst/queuelst.cpp queue/lst/queuelst.hpp queue/vec/queuevec.cpp queue/vec/queuevec.hpp

libtest2a = $(libtest1b) binarytree/binarytree.hpp binarytree/binarytree.cpp binarytree/lnk/binarytreelnk.hpp binarytree/lnk/binarytreelnk.cpp binarytree/vec/binarytreevec.hpp binarytree/vec/binarytreevec.cpp iterator/iterator.hpp

libtest2b = $(libtest2a) bst/bst.hpp bst/bst.cpp

libtest3 = $(libtest1a) hashtable/hashtable.hpp hashtable/hashtable.cpp hashtable/clsadr/htclsadr.hpp hashtable/clsadr/htclsadr.cpp hashtable/opnadr/htopnadr.hpp hashtable/opnadr/htopnadr.cpp

main: $(objects)
	$(cc) $(cflags) $(objects) -o main

clean:
	clear; rm -rfv *.o; rm -fv main

main.o: main.cpp
	$(cc) $(cflags) -c main.cpp

test.o: zlasdtest/test.cpp zlasdtest/test.hpp
	$(cc) $(cflags) -c zlasdtest/test.cpp -o test.o

mytest.o: zmytest/test.cpp zmytest/test.hpp
	$(cc) $(cflags) -c zmytest/test.cpp -o mytest.o

container.o: $(libcon) zlasdtest/container/container.cpp zlasdtest/container/container.hpp
	$(cc) $(cflags) -c zlasdtest/container/container.cpp -o container.o

exc1as.o: $(libexc1a) zlasdtest/exercise1a/simpletest.cpp
	$(cc) $(cflags) -c zlasdtest/exercise1a/simpletest.cpp -o exc1as.o

exc1af.o: $(libexc1a) zlasdtest/exercise1a/fulltest.cpp
	$(cc) $(cflags) -c zlasdtest/exercise1a/fulltest.cpp -o exc1af.o

exc1bs.o: $(libexc1b) zlasdtest/exercise1b/simpletest.cpp
	$(cc) $(cflags) -c zlasdtest/exercise1b/simpletest.cpp -o exc1bs.o

exc1bf.o: $(libexc1b) zlasdtest/exercise1b/fulltest.cpp
	$(cc) $(cflags) -c zlasdtest/exercise1b/fulltest.cpp -o exc1bf.o

exc2as.o: $(libexc2a) zlasdtest/exercise2a/simpletest.cpp
	$(cc) $(cflags) -c zlasdtest/exercise2a/simpletest.cpp -o exc2as.o

exc2af.o: $(libexc2a) zlasdtest/exercise2a/fulltest.cpp
	$(cc) $(cflags) -c zlasdtest/exercise2a/fulltest.cpp -o exc2af.o

exc2bs.o: $(libexc2b) zlasdtest/exercise2b/simpletest.cpp
	$(cc) $(cflags) -c zlasdtest/exercise2b/simpletest.cpp -o exc2bs.o

exc2bf.o: $(libexc2b) zlasdtest/exercise2b/fulltest.cpp
	$(cc) $(cflags) -c zlasdtest/exercise2b/fulltest.cpp -o exc2bf.o

exc3s.o: $(libexc3) zlasdtest/exercise3/simpletest.cpp
	$(cc) $(cflags) -c zlasdtest/exercise3/simpletest.cpp -o exc3s.o

exc3f.o: $(libexc3) zlasdtest/exercise3/fulltest.cpp
	$(cc) $(cflags) -c zlasdtest/exercise3/fulltest.cpp -o exc3f.o

test1a.o: $(libtest1a) zmytest/test1a/test1a.cpp
	$(cc) $(cflags) -c zmytest/test1a/test1a.cpp -o test1a.o

test1b.o: $(libtest1b) zmytest/test1b/test1b.cpp
	$(cc) $(cflags) -c zmytest/test1b/test1b.cpp -o test1b.o

test2a.o: $(libtest2a) zmytest/test2a/test2a.cpp
	$(cc) $(cflags) -c zmytest/test2a/test2a.cpp -o test2a.o

test2b.o: $(libtest2b) zmytest/test2b/test2b.cpp
	$(cc) $(cflags) -c zmytest/test2b/test2b.cpp -o test2b.o

test3.o: $(libtest3) zmytest/test3/test3.cpp
	$(cc) $(cflags) -c zmytest/test3/test3.cpp -o test3.o
