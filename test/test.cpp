#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "java.hpp"
#include "Seed.hpp"

TEST_CASE("Seed")
{
	Seed gen(uR"(काचं शक्नोम्यत्तुम् । नोपहिनस्ति माम् ॥)");
	CHECK(gen.get() == -1192045740);
	gen.set(uR"(ὕαλον ϕαγεῖν δύναμαι· τοῦτο οὔ με βλάπτει.)");
	CHECK(gen.get() == 1511720149);
	gen.set(uR"(Je peux manger du verre, ça ne me fait pas mal.)");
	CHECK(gen.get() == 882621516);
	gen.set(uR"(᚛᚛ᚉᚑᚅᚔᚉᚉᚔᚋ ᚔᚈᚔ ᚍᚂᚐᚅᚑ ᚅᚔᚋᚌᚓᚅᚐ᚜)");
	CHECK(gen.get() == -1604655271);
	gen.set(uR"(ᛁᚳ᛫ᛗᚨᚷ᛫ᚷᛚᚨᛋ᛫ᛖᚩᛏᚪᚾ᛫ᚩᚾᛞ᛫ᚻᛁᛏ᛫ᚾᛖ᛫ᚻᛖᚪᚱᛗᛁᚪᚧ᛫ᛗᛖ᛬)");
	CHECK(gen.get() == -841541790);
	gen.set(uR"(⠊⠀⠉⠁⠝⠀⠑⠁⠞⠀⠛⠇⠁⠎⠎⠀⠁⠝⠙⠀⠊⠞⠀⠙⠕⠑⠎⠝⠞⠀⠓⠥⠗⠞⠀⠍⠑)");
	CHECK(gen.get() == -1458216867);
	gen.set(uR"(Я могу есть стекло, оно мне не вредит.)");
	CHECK(gen.get() == -1392784639);
	gen.set(uR"(मैं काँच खा सकता हूँ और मुझे उससे कोई चोट नहीं पहुंचती.)");
	CHECK(gen.get() == 1117023627);
	gen.set(uR"(私はガラスを食べられます。それは私を傷つけません。)");
	CHECK(gen.get() == -302733627);
	gen.set("-1192045740");
	CHECK(gen.get() == -1192045740);
	gen.set("+1511720149");
	CHECK(gen.get() == 1511720149);
	gen.set("882621516");
	CHECK(gen.get() == 882621516);
	gen.set("-");
	CHECK(gen.get() == 45);
	gen.set("+");
	CHECK(gen.get() == 43);
	gen.set("");
	CHECK(gen.get() == 0);
}
