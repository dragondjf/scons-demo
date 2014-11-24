# make all .c or .cpp ->.o
$(obj)%.o:	%.c
	@echo "Compling: " $(addsuffix .c, $(basename $(notdir $@)))
	$(CC) $(CFLAGS) -c $< -o $@

$(obj)%.o:	%.cpp
	@echo "Compling: " $(addsuffix .cpp, $(basename $(notdir $@)))
	$(CXX) $(CFLAGS) -c $< -o $@

$(ShareLib):  $(SRC_C) $(SRC_CPP)
	@echo "Generating share library: " $(notdir $@)
	$(CXX)  -shared -Wl,--out-implib ${CFLAGS} $^ -o $@

# make all .c or .cpp ->.depend

$(obj).depend:$(SRC_C) $(SRC_CPP)
	@rm -f $@
	@for f in $(SRC_C); do \
		g=`basename $$f | sed -e 's/\(.*\)\.\w/\1.o/'`; \
		$(CC) -MM $(CFLAGS) -E -MQ $(_obj)$$g $$f >> $@ ; \
	done
	@for f in $(SRC_CPP); do \
		g=`basename $$f | sed -e 's/\(.*\)\...\w/\1.o/'`; \
		$(CC) -MM $(CFLAGS) -E -MQ $(_obj)$$g $$f >> $@ ; \
	done