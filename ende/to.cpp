//#include <windows.h>
#include <stdio.h>
//#include <io.h>
#include <stdlib.h>
//#include "../pdf2txt.h"
using namespace std;

void ConvertPDFBuffer2TextBuffer(char *pdffile, char *textfile)
{
    int m_iFileLength = 0;
    char* pdfBuffer = NULL;
    FILE *file = fopen(pdffile,"rb");
    if(file)
    {
        
        m_iFileLength = _filelength(fileno(file));
        if(m_iFileLength <= 0)
        {
            fclose(file)
            return;
        }
        pdfBuffer = new char[m_iFileLength];
        if(pdfBuffer == NULL)
        {
            fclose(file);
            return;
        }
        memset(pdfBuffer,0,m_iFileLength);
        fread(pdfBuffer,1,m_iFileLength,file);
        fclose(file);
    }
    if(pdfBuffer == NULL || m_iFileLength <= 0)
        return;
    SetPageSeparator("<<<<<<<<<********>>>>>>>>>>>>>");
    SetZoomRatio(100);
    SetTXTFormat(1);
    SetOpenResultFile(0);
    SetDeleteBlankLine(TRUE);
    
    int textBufferSize;
    const char *textbuffer = PDFBuffer2TextBuffer(pdfBuffer, m_iFileLength, &textBufferSize);
    if(textbuffer)
        printf("%s\n",textbuffer);
        PDF2TextFreeBuffer(textbuffer);
    LPCWSTR textbufferW = PDFBuffer2TextBufferW(pdfBuffer, m_iFileLength, &textBufferSize);
    PDF2TextFreeBufferW(textbufferW);
    textbufferW = PDFBuffer2TextBufferWEx(pdfBuffer,m_iFileLength,&textBufferSize,0, 0,NULL,NULL,NULL,0);
    PDF2TextFreeBufferW(textbufferW);
    delete []pdfBuffer;
}

int main()
{
    
	ConvertPDFBuffer2TextBuffer("Lab Manual 2014.pdf", "yourfileOutput.txt");
    
    return 0;
    
}
