#compiler_options = -std=c++17
# compiler_options = -mmacosx-version-min=10.7 -std=c++17 -stdlib=libc++
sources=\
	AST \
	Commands \
	ErrorHandler \
	Options \
	Util


output_dir = dist
obj_dir = obj
compiler_options = -std=c++17

sep = @echo ----------------------------
compile_cmd = g++ -c {}.cpp -o $(obj_dir)/{}.o $(compiler_options)

ifeq ($(OS),Windows_NT)
	RM := cmd /c rmdir /s /q {}
	MK := cmd /c mkdir {}
	EXE := ast.exe
else
	RM := rm -rf {} || true
	MK := mkdir -p {} || true
	EXE := ast
endif


build:
	@make cleandir
	$(sep)
	@echo Compiling with command: $(compile_cmd) 
	$(sep)
	@make compile
	@echo Linking...
	@make link

cleandir:
	-@$(subst {}, $(output_dir),$(RM))
	-@$(subst {}, $(output_dir),$(MK))
	-@$(subst {}, $(obj_dir),$(RM))
	-@$(subst {}, $(obj_dir),$(MK))

link:
	cd $(obj_dir) && g++ -o ../$(output_dir)/$(EXE) $(foreach s,$(sources),$s.o)
	$(sep)
	@echo Finished. Created $(output_dir)/$(EXE)!
	$(sep)

compile:
	@for s in $(sources); do echo Compiling $$s.cpp...; $(subst {},$$s,$(compile_cmd)); done
	$(sep)
	@echo Finished.
