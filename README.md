# pdfresurrect
**PDFResurrect** is a tool aimed at analyzing PDF documents.  The PDF format allows
for previous document changes to be retained in a more recent version of the
document, thereby creating a running history of changes for the document.  This
tool attempts to modify the PDF so that a reading utility will be presented with
the previous versions of the PDF.  The modified "versions" will be generated
as new PDF files leaving the original PDF unmodified.

```
Usage: pdfresurrect <file.pdf> [-i] [-w] [-q]
-i   Display PDF creator information
-w   Write the PDF versions and summary to disk
-q   Display only the number of versions contained in the PDF
```

And if built with `#define PDFRESURRECT_EXPERIMENTAL`:

```
-s Scrub the previous history data from the specified PDF
```

# Notes
If built with `#define PDFRESURRECT_EXPERIMENTAL`,
the scrubbing feature (`-s`) should not be trusted for any serious security
uses.  After using this experimental feature, please verify that it in fact
zero'd all of the objects that were of concern (those objects that were to be
zero'd).  Currently this feature will likely not render a working pdf.

This tool relies on the application reading the `pdfresurrect` extracted versions
to treat the last `xref` table as the most recent in the document.  This should
typically be the case.

The verbose output, which tries to deduce the PDF object type (e.g. stream,
page), is not always accurate, and the object counts might not be 100%
accurate.  However, this should not prevent the extraction of the versions.
This output is merely to provide a hint for the user as to what might be
different between the documents.

Object counts might appear off in linearized PDF documents.  That is not truly
the case, the reason for this is that each version of the PDF consists of the
objects that compose the linear portion of the PDF plus all of the objects that
compose the version in question.  Suppose there is a linearized PDF with 59
objects in its linear portion, and suppose the PDF has a second version that
consists of 21 objects.  The total number of objects in "version 2"
would be 59 + 21 or 80 objects.


# Building
## Linux
From the top-level directory of `pdfresurrect` run:

```bash
./configure
make
```

To install/uninstall the resulting binary to a specific path
the `--prefix=` flag can be used:

```bash
./configure --prefix=/my/desired/path/
```

Debugging mode can be enabled when configuring by using the following option:

```bash
./configure --enable-debug
```

The resulting binary can be placed anywhere, however it can also be
installed/uninstalled to the configured path automatically.  If no path was
specified at configure time, the default is `/usr/local/bin`. To install/uninstall:

```bash
make install
```
or
```bash
make uninstall
```

# Windows


# Thanks

* The rest of the 757/757Labs crew.
* GNU (https://www.gnu.org).
* All of the contributors: See [AUTHORS](./AUTHORS) file.


# Contact / Project URL
mattdavis9@gmail.com

https://github.com/enferex/pdfresurrect
