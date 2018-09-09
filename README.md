# History of this code

In the early 2000s, while still being a teenager, I was an avid user of Aedit under DOS. It was fast and powerful, and I had been using it since I was a kid.

Sadly, it was not able to handle long file names nor had any integration with the Windows clipboard (two features I wanted). Looking around for solutions, I stumbled upon a [website](http://martin.zutphen.nu/aedit/) of a gentleman that had written to Intel and got authorization to use Aedit however he saw fit.

Inspired by his story, I decided to write Intel to ask for the source code of the editor, which they provided as seen on the initial commit of this repo. I was surprised to find it written in PL/M, and not having access to PL/M 86, my teenage idea of adding features to it was put on a very long hold.

Sometime later I rediscovered the Zip file with the source code, and decided to write to Martin Meijerink again to offer him the file, as at least he had a website about it. He accepted it and posted it with a note.

Sadly, the original mails got lost (my mail inbox size back then was 1 Mb, and I'm unable to find any backups), so I reproduce here the story as faithful as possible.

# Current status

Several times I tried to translate by hand the whole source code to C, but being unable to fully test it as I progressed, I stopped. That was the situation until a few months ago, when I found the missing piece of the Puzzle: a PL/M 86 compiler.

Armed with it, and Borland C++, I plan to translate the initial code to C while trying to keep it as close as possible to the original. To do this, I've been working on DOSBox / DOSEmu / QEMU, and managed 2 milestones:

1. Compile the original PL/M code
2. Link PL/M and C using Borland's TLINK. To achieve this, two things are needed.
   - In C, functions need to be declared as `pascal`.
   - PL/M obj files need to be modified so the segments are named `_TEXT` and `_DATA`, instead of the PL/M defaults `CODE` and `DATA`. I have a quick and dirty piece of C to perform this change.

I've also toyed with other ideas:
- Modifying TCC frontend to take PL/M as it's input (thus creating a modern PL/M compiler).
- Modifying PLM86 to produce the `obj`s with the needed segment names. This will save me from copying files out of the virtualized environment and back in.
- Use the plm2c open source tool that is available online, but sadly it chokes on Aedit's source code.

# Why the translation

Because as an user of VIM, I believe there is still some space for a simple, easy to understand, and powerful editor like Aedit. When colleagues ask me what do I see in it, I like to explain it as a crossbreed between the simple interface of nano (with the menu on bottom) and the power of vim, except that it was born before both (I think it traces its origins back to the 70's `ALTER`, the original name of the editor). Surely, it won't start another editors war, but is a nice exercise on computer history.