CROSSBRIDGE:= ~/bin/crossbridge/sdk

all:
	echo "make <native/flash/vfs>"

native:
	g++ main.cpp -o native

flash:
	g++ main.cpp -o flash

vfs:
	genfs --type=embed . vfsprefix
	java -jar $(CROSSBRIDGE)/usr/lib/asc2.jar -merge -md -abcfuture -AS3 \
	-import $(CROSSBRIDGE)/usr/lib/builtin.abc \
	-import $(CROSSBRIDGE)/usr/lib/playerglobal.abc \
	-import $(CROSSBRIDGE)/usr/lib/BinaryData.abc \
	-import $(CROSSBRIDGE)/usr/lib/ISpecialFile.abc \
	-import $(CROSSBRIDGE)/usr/lib/IBackingStore.aBC \
	-import $(CROSSBRIDGE)/usr/lib/IVFS.abc \
	-import $(CROSSBRIDGE)/usr/lib/InMemoryBackingStore.abc \
	-import $(CROSSBRIDGE)/usr/lib/PlayerKernel.abc \
	vfsprefix*.as -outdir . -out embedvfs

	java -jar $(CROSSBRIDGE)/usr/lib/asc2.jar -merge -md -abcfuture -AS3 \
	-import $(CROSSBRIDGE)/usr/lib/builtin.abc \
	-import $(CROSSBRIDGE)/usr/lib/playerglobal.abc \
	-import $(CROSSBRIDGE)/usr/lib/BinaryData.abc \
	-import $(CROSSBRIDGE)/usr/lib/ISpecialFile.abc \
	-import $(CROSSBRIDGE)/usr/lib/IBackingStore.aBC \
	-import $(CROSSBRIDGE)/usr/lib/IVFS.abc \
	-import $(CROSSBRIDGE)/usr/lib/InMemoryBackingStore.abc \
	-import $(CROSSBRIDGE)/usr/lib/PlayerKernel.abc \
	Console.as -outdir . 

	g++ main.cpp embedvfs.abc -symbol-abc=Console.abc --emit-swf -o vfs.swf

clean:
	rm -rf vfs* embedvfs.abc Console.abc unexistringDir native flash
