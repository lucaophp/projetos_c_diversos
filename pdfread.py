import PyPDF2
import sys
pdfFileObj = open(sys.argv[1], 'rb')
pr = PyPDF2.PdfFileReader(pdfFileObj)
pageObj = pr.getPage(0)
text = pageObj.extractText()
print(text)
