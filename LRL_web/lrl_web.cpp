#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include <errno.h>
#include <bits/stdc++.h>

#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>

#include "do_posix_spawn.h"

#define LRL_WEB_DEBUG 0
#define NUMOPS_MAX 10
#define LRL_WEB_USER std::string("yaya")

using namespace std;
using namespace cgicc;

void  dumpList(const Cgicc& formData); 
void  process(const Cgicc& formData); 

std::string tmp_lrl_web;  //directory for processing
std::string myls;
int main(int argc, 
     char **argv)
{
   char buf[1024];
   std::string xbufstr;
   xbufstr=std::string("/home/")+LRL_WEB_USER+std::string("/public_html/cgi-bin/make_lrl_web_dir.bash");
   if (do_exec_to_buffer(xbufstr.c_str(),buf,1024)!=0)
       exit(-1);
   tmp_lrl_web=std::string(buf);
   try {
      Cgicc cgi;

      // Send HTTP header
      std::cout << HTTPHTMLHeader() << std::endl;

      // Set up the HTML document" << std::endl;
      std::cout << html() << std::endl;
      std::cout << "<HEAD>" << std::endl;
      std::cout << "	<meta charset=\"utf-8\">" << std::endl;
      std::cout << " 	" << std::endl;
      std::cout << " <script  type=\"text/javascript\">" << std::endl;
      std::cout << " const EventListenerMode = {capture: true};" << std::endl;
      std::cout << " " << std::endl;
      std::cout << "function preventGlobalMouseEvents () {" << std::endl;
      std::cout << "  document.body.style['pointer-events'] = 'none';" << std::endl;
      std::cout << "  return true;" << std::endl;
      std::cout << "}" << std::endl;
      std::cout << "" << std::endl;
      std::cout << "function restoreGlobalMouseEvents () {" << std::endl;
      std::cout << "  document.body.style['pointer-events'] = 'auto';" << std::endl;
      std::cout << "  return;" << std::endl;
      std::cout << "}" << std::endl;
      std::cout << "" << std::endl;
      std::cout << "function mousemoveListener (e) {" << std::endl;
      std::cout << "  e.stopPropagation ();" << std::endl;
      std::cout << "  // do whatever is needed while the user is moving the cursor around" << std::endl;
      std::cout << "  return true;" << std::endl;
      std::cout << "}" << std::endl;
      std::cout << "" << std::endl;
      std::cout << "function mouseupListener (e) {" << std::endl;
      std::cout << "  restoreGlobalMouseEvents ();" << std::endl;
      std::cout << "  document.removeEventListener ('mouseup',   mouseupListener,   EventListenerMode);" << std::endl;
      std::cout << "  document.removeEventListener ('mousemove', mousemoveListener, EventListenerMode);" << std::endl;
      std::cout << "  e.stopPropagation ();" << std::endl;
      std::cout << "  return true;" << std::endl;
      std::cout << "}" << std::endl;
      std::cout << " " << std::endl;
      std::cout << "function captureMouseEvents (e) {" << std::endl;
      std::cout << "  preventGlobalMouseEvents ();" << std::endl;
      std::cout << "  document.addEventListener ('mouseup',   mouseupListener,   EventListenerMode);" << std::endl;
      std::cout << "  document.addEventListener ('mousemove', mousemoveListener, EventListenerMode);" << std::endl;
      std::cout << "  e.preventDefault ();" << std::endl;
      std::cout << "  e.stopPropagation ();" << std::endl;
      std::cout << "  return true;" << std::endl;
      std::cout << "}" << std::endl;
      std::cout << "" << std::endl;
      std::cout << "function twodig(myint) {" << std::endl;
      std::cout << "  if (myint<10) {" << std::endl;
      std::cout << "    return \"0\"+myint;" << std::endl;
      std::cout << "  } else {" << std::endl;
      std::cout << "    return \"\"+myint;" << std::endl;
      std::cout << "  }" << std::endl;
      std::cout << "}" << std::endl;
      std::cout << "" << std::endl;
      std::cout << "function setchaininput(row){" << std::endl;
      std::cout << "    let rownum=parseInt(row);" << std::endl;
      std::cout << "    if (rownum < 2) {" << std::endl;
      std::cout << "      let firstrow=document.getElementById(\"chain_01\");" << std::endl;
      std::cout << "      if (!(firstrow.value===\"new_input\")){" << std::endl;
      std::cout << "        alert(\"Request for data prior to row 1 ignored\");" << std::endl;
      std::cout << "      }" << std::endl;
      std::cout << "      firstrow.value=\"new_input\";" << std::endl;
      std::cout << "      document.getElementById(\"block_01\").style=\"display:inline\";" << std::endl;
      std::cout << "      document.getElementById(\"block_01a\").style=\"display:inline\";" << std::endl;
      std::cout << "      document.getElementById(\"block_01b\").style=\"display:inline\";" << std::endl;
      std::cout << "      document.getElementById(\"block_01c\").style=\"display:inline\";" << std::endl;
      std::cout << "      return true;" << std::endl;
      std::cout << "    } else if (rownum > "<<NUMOPS_MAX<<") {" << std::endl;
      std::cout << "      alert(\"Request for data after row "<<NUMOPS_MAX<<" ignored\");" << std::endl;
      std::cout << "      return false;" << std::endl;
      std::cout << "    }" << std::endl;
      std::cout << "    let priornum=rownum-1;" << std::endl;
      std::cout << "    if (document.getElementById(\"chain_\"+twodig(rownum)).value==\"chain_input\") {" << std::endl;
      std::cout << "      document.getElementById(\"block_\"+twodig(priornum)+\"c\").style=\"display:inline\";" << std::endl;
      std::cout << "      document.getElementById(\"block_\"+twodig(rownum)+\"b\").style=\"display:none\";" << std::endl;
      std::cout << "    } else {" << std::endl;
      std::cout << "      document.getElementById(\"block_\"+twodig(rownum)+\"b\").style=\"display:inline\";" << std::endl;
      std::cout << "    }" << std::endl;
      std::cout << "    document.getElementById(\"block_\"+twodig(rownum)).style=\"display:inline\";" << std::endl;
      std::cout << "    document.getElementById(\"block_\"+twodig(rownum)+\"a\").style=\"display:inline\";" << std::endl;
      std::cout << "    document.getElementById(\"block_\"+twodig(rownum)+\"c\").style=\"display:inline\";" << std::endl;
      std::cout << "    return true;" << std::endl;
      std::cout << "}" << std::endl;
      std::cout << "" << std::endl;
      std::cout << "function changenumops(){" << std::endl;
      std::cout << "  var ii;" << std::endl;
      std::cout << "  let mynumops=parseInt(document.getElementById(\"numops\").value);" << std::endl;
      std::cout << "  if (mynumops < 1) mynumops=1;" << std::endl;
      std::cout << "  if (mynumops > "<<NUMOPS_MAX<<") mynumops="<<NUMOPS_MAX<<";" << std::endl;
      std::cout << "  document.getElementById(\"numops\").value=mynumops.toString();" << std::endl;
      std::cout << "  for (ii=1; ii<mynumops+1;ii++) {" << std::endl;
      std::cout << "    // alert(\"enable block_\"+twodig(ii));" << std::endl;
      std::cout << "    let mychain=document.getElementById(\"chain_\"+twodig(ii)).value;" << std::endl;
      std::cout << "    document.getElementById(\"block_\"+twodig(ii)).style=\"display:inline\";" << std::endl;
      std::cout << "    document.getElementById(\"block_\"+twodig(ii)+\"a\").style=\"display:inline\";" << std::endl;
      std::cout << "    if (mychain!=\"chain_input\") {" << std::endl;
      std::cout << "      document.getElementById(\"block_\"+twodig(ii)+\"b\").style=\"display:inline\";" << std::endl;
      std::cout << "    } else {" << std::endl;
      std::cout << "      document.getElementById(\"block_\"+twodig(ii)+\"b\").style=\"display:none\";" << std::endl;
      std::cout << "    }" << std::endl;
      std::cout << "    document.getElementById(\"block_\"+twodig(ii)+\"c\").style=\"display:inline\";" << std::endl;
      std::cout << "  }" << std::endl;
      std::cout << "  if (mynumops < "<<NUMOPS_MAX<<") {" << std::endl;
      std::cout << "  for (ii=mynumops+1; ii<"<<NUMOPS_MAX+1<<";ii++) {" << std::endl;
      std::cout << "    // alert(\"disable block_\"+twodig(ii));" << std::endl;
      std::cout << "    document.getElementById(\"block_\"+twodig(ii)).style=\"display:none\";" << std::endl;
      std::cout << "    document.getElementById(\"block_\"+twodig(ii)+\"a\").style=\"display:none\";" << std::endl;
      std::cout << "    document.getElementById(\"block_\"+twodig(ii)+\"b\").style=\"display:none\";" << std::endl;
      std::cout << "    document.getElementById(\"block_\"+twodig(ii)+\"c\").style=\"display:none\";" << std::endl;
      std::cout << "  }" << std::endl;
      std::cout << "  }" << std::endl;
      std::cout << "  return true;" << std::endl;
      std::cout << "" << std::endl;
      std::cout << "}" << std::endl;
      std::cout << "" << std::endl;
      std::cout << "function pfloat(pfield){" << std::endl;
      std::cout << "    // validate for non-negative float   " << std::endl;
      std::cout << "    var charsAllowed=\"0123456789.+\";" << std::endl;
      std::cout << "    var allowed;" << std::endl;
      std::cout << "    var plusfound;" << std::endl;
      std::cout << "    var dotfound;" << std::endl;
      std::cout << "    plusfound = 0;" << std::endl;
      std::cout << "    dotfound = 0;" << std::endl;
      std::cout << "    for(var i=0;i<pfield.value.length;i++){       " << std::endl;
      std::cout << "        allowed=false;" << std::endl;
      std::cout << "        for(var j=0;j<charsAllowed.length;j++){" << std::endl;
      std::cout << "            if( pfield.value.charAt(i)==charsAllowed.charAt(j) ){ " << std::endl;
      std::cout << "               allowed=true;" << std::endl;
      std::cout << "               if (j == 11) {" << std::endl;
      std::cout << "                 plusfound++;" << std::endl;
      std::cout << "                 allowed=false;" << std::endl;
      std::cout << "                 plusfound--;" << std::endl;
      std::cout << "                 break;" << std::endl;
      std::cout << "               } else if (j == 10) {" << std::endl;
      std::cout << "                 dotfound++;" << std::endl;
      std::cout << "                 if (dotfound > 1) {" << std::endl;
      std::cout << "                   allowed=false;" << std::endl;
      std::cout << "                   dotfound--;" << std::endl;
      std::cout << "                   break;" << std::endl;
      std::cout << "                 }" << std::endl;
      std::cout << "               } " << std::endl;
      std::cout << "               break;" << std::endl;
      std::cout << "            }" << std::endl;
      std::cout << "        }" << std::endl;
      std::cout << "        if(allowed==false){ pfield.value = pfield.value.replace(pfield.value.charAt(i),\"\"); i--; }" << std::endl;
      std::cout << "    }" << std::endl;
      std::cout << "    return true;" << std::endl;
      std::cout << "}" << std::endl;
      std::cout << "" << std::endl;
      std::cout << "function gfloat(field){" << std::endl;
      std::cout << "    // validate for float   " << std::endl;
      std::cout << "    var charsAllowed=\"0123456789.+-\";" << std::endl;
      std::cout << "    var allowed;" << std::endl;
      std::cout << "    var plusminusfound;" << std::endl;
      std::cout << "    var dotfound;" << std::endl;
      std::cout << "    plusminusfound = 0;" << std::endl;
      std::cout << "    dotfound = 0;" << std::endl;
      std::cout << "    otherfound = 0;" << std::endl;
      std::cout << "    for(var i=0;i<field.value.length;i++){       " << std::endl;
      std::cout << "        allowed=false;" << std::endl;
      std::cout << "        for(var j=0;j<charsAllowed.length;j++){" << std::endl;
      std::cout << "            if( field.value.charAt(i)==charsAllowed.charAt(j) ){ " << std::endl;
      std::cout << "               allowed=true;" << std::endl;
      std::cout << "               if (j == 11 || j == 12) {" << std::endl;
      std::cout << "                 if (otherfound>0 || dotfound>0 || plusminusfound>0) {" << std::endl;
      std::cout << "                   allowed=false;" << std::endl;
      std::cout << "                 } else {" << std::endl;
      std::cout << "                 plusminusfound++;" << std::endl;
      std::cout << "                 }" << std::endl;
      std::cout << "               } else if (j == 10) {" << std::endl;
      std::cout << "                 if (dotfound>0) {" << std::endl;
      std::cout << "                   allowed=false;" << std::endl;
      std::cout << "                 } else {" << std::endl;
      std::cout << "                 dotfound++;" << std::endl;
      std::cout << "                 } " << std::endl;
      std::cout << "               } else {" << std::endl;
      std::cout << "                 otherfound++;" << std::endl;
      std::cout << "               } " << std::endl;
      std::cout << "            }" << std::endl;
      std::cout << "        }" << std::endl;
      std::cout << "        if(allowed==false){ field.value = field.value.replace(field.value.charAt(i),\"\"); i--; }" << std::endl;
      std::cout << "    }" << std::endl;
      std::cout << "    return true;" << std::endl;
      std::cout << "}" << std::endl;
      std::cout << "" << std::endl;
      std::cout << "</script>" << std::endl;
      std::cout << "" << std::endl;
      std::cout << "<TITLE>" << std::endl;
      std::cout << "LRL_WEB Lattice Representation Library Tool Web Page" << std::endl;
      std::cout << "</TITLE> " << std::endl;
      std::cout << "</HEAD> " << std::endl;
      std::cout << "" << std::endl;
      std::cout << "" << std::endl;
      std::cout << "<BODY>" << std::endl;
      std::cout << "<font face=\"Arial,Helvetica,Times\" size=\"3\">" << std::endl;
      std::cout << "<hr />" << std::endl;
      std::cout << "<center>" << std::endl;
      std::cout << "Buffer: " << "'"+tmp_lrl_web+"'" <<std::endl;

      // Dump form 
     if (LRL_WEB_DEBUG)  dumpList(cgi);

      // Process form
      process(cgi);

      // Close the HTML document
      std::cout << "</BODY>" << std::endl;
      std::cout << "</HTML>" << std::endl;
   }
   catch(exception& e) {
      // handle any errors - omitted for brevity
   }
}

// Convert line breaks and special characters to HTML 
 std::string plaintext2html(std::string & dst, std::string src)
{
    size_t dstlen, srclen, ii;
    char c;
    srclen=src.length();
    dstlen=dst.length();
    if (dstlen>0){
      dst.clear();
      dstlen=0;
    }
    for(ii=0;ii<srclen;ii++){
      c=src[ii];
      switch (c) {
        case('\n'):
          dst.append("<br/>");
          break;
        case('\r'):
          dst.append("<br/>");
          if(ii<srclen-1 && src[ii+1]=='\n') ii++;
          break;
        case('&'):
          dst.append("&amp;");
          break;
        case('<'):
          dst.append("&lt;");
          break;
        case('>'):
          dst.append("&gt;");
          break;
        case(0):
          dst.append("&#0;");
          break;
        default:
          dst.push_back(c);
          break;
      }
    }
    return dst;
}

  void  dumpList(const Cgicc& formData) 
   {
     std::string htstr;
     cout << h2("Form Data via vector") << std::endl; 
     cout << cgicc::div().set("align","center") << std::endl;
     cout << "<pre>"<<std::endl<<myls<<std::endl<<"</pre>"<<std::endl; 
     cout << table()<< std::endl;
     cout << tr().set("class","title") << td("Element <br /> Name") 
          << td("Element <br /> Value") << tr() << std::endl;
 
    // Iterate through the vector, and print out each value
     const_form_iterator iter;
     for(iter = formData.getElements().begin(); 
         iter != formData.getElements().end(); 
         ++iter) {
       cout << tr().set("class","data") << td(iter->getName()) 
            << td(plaintext2html(htstr,iter->getValue())) << tr() << std::endl;
     }
     cout << table() << cgicc::div() << std::endl;
  }


// Process the form
 void  process(const Cgicc& formData) 
 {
    cgicc::const_form_iterator numops_iter;
    cgicc::const_form_iterator lrl_web_data_iter;
    cgicc::const_form_iterator lrl_web_output_iter;
    cgicc::const_form_iterator chain_iter;
    cgicc::const_form_iterator operation_iter;
    ofstream operationfile;
    ofstream lrl_web_data_file;
    std::string lrl_web_data_data;
    std::string chain;
    std::string xactstr;
    size_t numops;
    size_t numop;
    std::string twodig_array[NUMOPS_MAX+1]={"00","01","02","03","04","05","06","07","08","09","10"
#if NUMOPS_MAX > 10
#if NUMOPS_MAX < 20
#define NUMOPS_MAX 20
#endif
    ,"11","12","13","14","15","16","17","18","19","20"
#endif
#if NUMOPS_MAX > 20
#if NUMOPS_MAX < 30
#define NUMOPS_MAX 30
#endif
    ,"21","22","23","24","25","26","27","28","29","30"
#endif
#if NUMOPS_MAX > 30
#if NUMOPS_MAX < 40
#define NUMOPS_MAX 40
#endif
    ,"31","32","33","34","35","36","37","38","39","40"
#endif
#if NUMOPS_MAX > 40
#if NUMOPS_MAX < 50
#define NUMOPS_MAX 50
#endif
    ,"41","42","43","44","45","46","47","48","49","50"
#endif
#if NUMOPS_MAX > 50
#if NUMOPS_MAX < 60
#define NUMOPS_MAX 60
#endif
    ,"51","52","53","54","55","56","57","58","59","60"
#endif
#if NUMOPS_MAX > 60
#if NUMOPS_MAX < 70
#define NUMOPS_MAX 70
#endif
    ,"61","62","63","64","65","66","67","68","69","70"
#endif
#if NUMOPS_MAX > 70
#if NUMOPS_MAX < 80
#define NUMOPS_MAX 80
#endif
    ,"71","72","73","74","75","76","77","78","79","80"
#endif
#if NUMOPS_MAX > 80
#if NUMOPS_MAX < 90
#define NUMOPS_MAX 90
#endif
    ,"81","82","83","84","85","86","87","88","89","90"
#endif
#if NUMOPS_MAX > 90
#if NUMOPS_MAX < 99
#define NUMOPS_MAX 99
#endif
    ,"91","92","93","94","95","96","97","98","99"
#endif
    };

    numops_iter = formData.getElement("numops");
    if (numops_iter == formData.getElements().end()) {
      numops = 0;
    } else {
      numops = (size_t)atol(numops_iter->getValue().c_str());
    }

    std::cout << "<hr />" << std::endl;
    std::cout << "<center>" << std::endl;
    std::cout << h2(" LRL_WEB, Lattice Representation Library Tool Web Page") << std::endl;
    std::cout << "<br /> by" << std::endl;
    std::cout << "<br /> Lawrence C. Andrews, Herbert J. Bernstein, Ronin Institute for Independent Scholarship," << std::endl;
    std::cout << "<br /><A HREF=mailto:lawrence.andrews@ronininstitute.org>lawrence.andrews@ronininstitute.org</A>" << std::endl;
    std::cout << "<a href=mailto:yayahjb@gmail.com>yayahjb@gmail.com</a><br />" << std::endl;
    xactstr=std::string("<FORM method=POST ACTION=\"http://192.168.1.222/~");
    xactstr+=LRL_WEB_USER;
    xactstr+=std::string("/cgi-bin/lrl_web.cgi\">");
    std::cout << xactstr  << std::endl;
    std::cout << "<br />" << std::endl;
    std::cout << "Assorted tools to do various calculations for crystallographic lattices." << std::endl;
    std::cout << "<br />" << std::endl;
    std::cout << "<STRONG>" << std::endl;
    std::cout << "Please read the <a href=\"#notice\">NOTICE</a> below before use of this web page" << std::endl;
    std::cout << "</STRONG>" << std::endl;
    std::cout << "<p>" << std::endl;
    std::cout << "<a name=\"search\"></a>" << std::endl;
    std::cout << "<INPUT type=\"submit\">" << std::endl;
    std::cout << "<INPUT type=\"reset\">" << std::endl;
    std::cout << "<br />" << std::endl;
    std::cout << "<input type=hidden name=\"OutputStyle\" value=\"TEXT\" />" << std::endl;
    std::cout << "<table border=2>" << std::endl;
    std::cout << "<tr><td valign=top>" << std::endl;
    std::cout << "  <table>" << std::endl;
    std::cout << "  <tr>" << std::endl;
    std::cout << "  <td colspan=3 align=\"center\">" << std::endl;
    std::cout << "  <label for=\"numops\">Number of operations: </label>" << std::endl;
    std::cout << "  <select name=\"numops\" id=\"numops\" onchange=\"changenumops()\" size=\"1\">" << std::endl;
    if (numops==1) {
      std::cout << "  <option selected value=\"1\">1</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"1\">1</option>" << std::endl;
    }
    if (numops==2) {
      std::cout << "  <option selected value=\"2\">2</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"2\">2</option>" << std::endl;
    }
    if (numops==3) {
      std::cout << "  <option selected value=\"3\">3</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"3\">3</option>" << std::endl;
    }
    if (numops==4) {
      std::cout << "  <option selected value=\"4\">4</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"4\">4</option>" << std::endl;
    }
    if (numops==5) {
      std::cout << "  <option selected value=\"5\">5</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"5\">5</option>" << std::endl;
    }
    if (numops==6) {
      std::cout << "  <option selected value=\"6\">6</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"6\">6</option>" << std::endl;
    }
    if (numops==7) {
      std::cout << "  <option selected value=\"7\">7</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"7\">7</option>" << std::endl;
    }
    if (numops==8) {
      std::cout << "  <option selected value=\"8\">8</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"8\">8</option>" << std::endl;
    }
    if (numops==9) {
      std::cout << "  <option selected value=\"9\">9</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"9\">9</option>" << std::endl;
    }
    if (numops==10) {
      std::cout << "  <option selected value=\"10\">10</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"10\">10</option>" << std::endl;
    }
#if NUMOPS_MAX>10
    if (numops==11) {
      std::cout << "  <option selected value=\"11\">11</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"11\">11</option>" << std::endl;
    }
    if (numops==12) {
      std::cout << "  <option selected value=\"12\">12</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"12\">12</option>" << std::endl;
    }
    if (numops==13) {
      std::cout << "  <option selected value=\"13\">13</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"13\">13</option>" << std::endl;
    }
    if (numops==14) {
      std::cout << "  <option selected value=\"14\">14</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"14\">14</option>" << std::endl;
    }
    if (numops==15) {
      std::cout << "  <option selected value=\"15\">15</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"15\">15</option>" << std::endl;
    }
    if (numops==16) {
      std::cout << "  <option selected value=\"16\">16</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"16\">16</option>" << std::endl;
    }
    if (numops==17) {
      std::cout << "  <option selected value=\"17\">17</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"17\">17</option>" << std::endl;
    }
    if (numops==18) {
      std::cout << "  <option selected value=\"18\">18</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"18\">18</option>" << std::endl;
    }
    if (numops==19) {
      std::cout << "  <option selected value=\"19\">19</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"19\">19</option>" << std::endl;
    }
    if (numops==20) {
      std::cout << "  <option selected value=\"20\">10</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"10\">20</option>" << std::endl;
    }
#endif
#if NUMOPS_MAX>10
    if (numops==21) {
      std::cout << "  <option selected value=\"21\">21</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"21\">21</option>" << std::endl;
    }
    if (numops==22) {
      std::cout << "  <option selected value=\"22\">22</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"22\">22</option>" << std::endl;
    }
    if (numops==23) {
      std::cout << "  <option selected value=\"23\">23</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"23\">23</option>" << std::endl;
    }
    if (numops==24) {
      std::cout << "  <option selected value=\"24\">24</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"24\">24</option>" << std::endl;
    }
    if (numops==25) {
      std::cout << "  <option selected value=\"25\">25</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"25\">25</option>" << std::endl;
    }
    if (numops==26) {
      std::cout << "  <option selected value=\"26\">26</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"26\">26</option>" << std::endl;
    }
    if (numops==27) {
      std::cout << "  <option selected value=\"27\">27</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"27\">27</option>" << std::endl;
    }
    if (numops==28) {
      std::cout << "  <option selected value=\"28\">28</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"28\">28</option>" << std::endl;
    }
    if (numops==29) {
      std::cout << "  <option selected value=\"29\">29</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"29\">29</option>" << std::endl;
    }
    if (numops==30) {
      std::cout << "  <option selected value=\"30\">30</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"30\">30</option>" << std::endl;
    }
#endif
#if NUMOPS_MAX>30
    if (numops==31) {
      std::cout << "  <option selected value=\"31\">31</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"31\">31</option>" << std::endl;
    }
    if (numops==32) {
      std::cout << "  <option selected value=\"32\">32</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"32\">32</option>" << std::endl;
    }
    if (numops==33) {
      std::cout << "  <option selected value=\"33\">33</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"33\">33</option>" << std::endl;
    }
    if (numops==34) {
      std::cout << "  <option selected value=\"34\">34</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"34\">34</option>" << std::endl;
    }
    if (numops==35) {
      std::cout << "  <option selected value=\"35\">35</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"35\">35</option>" << std::endl;
    }
    if (numops==36) {
      std::cout << "  <option selected value=\"36\">36</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"36\">36</option>" << std::endl;
    }
    if (numops==37) {
      std::cout << "  <option selected value=\"37\">37</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"37\">37</option>" << std::endl;
    }
    if (numops==38) {
      std::cout << "  <option selected value=\"38\">38</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"38\">38</option>" << std::endl;
    }
    if (numops==39) {
      std::cout << "  <option selected value=\"39\">39</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"39\">39</option>" << std::endl;
    }
    if (numops==40) {
      std::cout << "  <option selected value=\"40\">40</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"40\">40</option>" << std::endl;
    }
#endif
#if NUMOPS_MAX>40
    if (numops==41) {
      std::cout << "  <option selected value=\"41\">41</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"41\">41</option>" << std::endl;
    }
    if (numops==42) {
      std::cout << "  <option selected value=\"42\">42</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"42\">42</option>" << std::endl;
    }
    if (numops==43) {
      std::cout << "  <option selected value=\"43\">43</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"43\">43</option>" << std::endl;
    }
    if (numops==44) {
      std::cout << "  <option selected value=\"44\">44</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"44\">44</option>" << std::endl;
    }
    if (numops==45) {
      std::cout << "  <option selected value=\"45\">45</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"45\">45</option>" << std::endl;
    }
    if (numops==46) {
      std::cout << "  <option selected value=\"46\">46</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"46\">46</option>" << std::endl;
    }
    if (numops==47) {
      std::cout << "  <option selected value=\"47\">47</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"47\">47</option>" << std::endl;
    }
    if (numops==48) {
      std::cout << "  <option selected value=\"48\">48</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"48\">48</option>" << std::endl;
    }
    if (numops==49) {
      std::cout << "  <option selected value=\"49\">49</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"49\">49</option>" << std::endl;
    }
    if (numops==50) {
      std::cout << "  <option selected value=\"50\">50</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"50\">50</option>" << std::endl;
    }
#endif
#if NUMOPS_MAX>50
    if (numops==51) {
      std::cout << "  <option selected value=\"51\">51</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"51\">51</option>" << std::endl;
    }
    if (numops==52) {
      std::cout << "  <option selected value=\"52\">52</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"52\">52</option>" << std::endl;
    }
    if (numops==53) {
      std::cout << "  <option selected value=\"53\">53</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"53\">53</option>" << std::endl;
    }
    if (numops==54) {
      std::cout << "  <option selected value=\"54\">54</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"54\">54</option>" << std::endl;
    }
    if (numops==55) {
      std::cout << "  <option selected value=\"55\">55</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"55\">55</option>" << std::endl;
    }
    if (numops==56) {
      std::cout << "  <option selected value=\"56\">56</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"56\">56</option>" << std::endl;
    }
    if (numops==57) {
      std::cout << "  <option selected value=\"57\">57</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"57\">57</option>" << std::endl;
    }
    if (numops==58) {
      std::cout << "  <option selected value=\"58\">58</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"58\">58</option>" << std::endl;
    }
    if (numops==59) {
      std::cout << "  <option selected value=\"59\">59</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"59\">59</option>" << std::endl;
    }
    if (numops==60) {
      std::cout << "  <option selected value=\"60\">60</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"60\">60</option>" << std::endl;
    }
#endif
#if NUMOPS_MAX>60
    if (numops==61) {
      std::cout << "  <option selected value=\"61\">61</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"61\">61</option>" << std::endl;
    }
    if (numops==62) {
      std::cout << "  <option selected value=\"62\">62</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"62\">62</option>" << std::endl;
    }
    if (numops==63) {
      std::cout << "  <option selected value=\"63\">63</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"63\">63</option>" << std::endl;
    }
    if (numops==64) {
      std::cout << "  <option selected value=\"64\">64</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"64\">64</option>" << std::endl;
    }
    if (numops==65) {
      std::cout << "  <option selected value=\"65\">65</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"65\">65</option>" << std::endl;
    }
    if (numops==66) {
      std::cout << "  <option selected value=\"66\">66</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"66\">66</option>" << std::endl;
    }
    if (numops==67) {
      std::cout << "  <option selected value=\"67\">67</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"67\">67</option>" << std::endl;
    }
    if (numops==68) {
      std::cout << "  <option selected value=\"68\">68</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"68\">68</option>" << std::endl;
    }
    if (numops==69) {
      std::cout << "  <option selected value=\"69\">69</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"69\">69</option>" << std::endl;
    }
    if (numops==70) {
      std::cout << "  <option selected value=\"70\">70</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"70\">70</option>" << std::endl;
    }
#endif
#if NUMOPS_MAX>70
    if (numops==71) {
      std::cout << "  <option selected value=\"71\">71</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"71\">71</option>" << std::endl;
    }
    if (numops==72) {
      std::cout << "  <option selected value=\"72\">72</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"72\">72</option>" << std::endl;
    }
    if (numops==73) {
      std::cout << "  <option selected value=\"73\">73</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"73\">73</option>" << std::endl;
    }
    if (numops==74) {
      std::cout << "  <option selected value=\"74\">74</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"74\">74</option>" << std::endl;
    }
    if (numops==75) {
      std::cout << "  <option selected value=\"75\">75</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"75\">75</option>" << std::endl;
    }
    if (numops==76) {
      std::cout << "  <option selected value=\"76\">76</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"76\">76</option>" << std::endl;
    }
    if (numops==77) {
      std::cout << "  <option selected value=\"77\">77</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"77\">77</option>" << std::endl;
    }
    if (numops==78) {
      std::cout << "  <option selected value=\"78\">78</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"78\">78</option>" << std::endl;
    }
    if (numops==79) {
      std::cout << "  <option selected value=\"79\">79</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"9\">9</option>" << std::endl;
    }
    if (numops==80) {
      std::cout << "  <option selected value=\"80\">80</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"80\">80</option>" << std::endl;
    }
#endif
#if NUMOPS_MAX>80
    if (numops==81) {
      std::cout << "  <option selected value=\"81\">81</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"81\">81</option>" << std::endl;
    }
    if (numops==82) {
      std::cout << "  <option selected value=\"82\">82</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"82\">82</option>" << std::endl;
    }
    if (numops==83) {
      std::cout << "  <option selected value=\"83\">83</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"83\">83</option>" << std::endl;
    }
    if (numops==84) {
      std::cout << "  <option selected value=\"84\">84</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"84\">84</option>" << std::endl;
    }
    if (numops==85) {
      std::cout << "  <option selected value=\"85\">85</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"85\">85</option>" << std::endl;
    }
    if (numops==86) {
      std::cout << "  <option selected value=\"86\">86</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"86\">86</option>" << std::endl;
    }
    if (numops==87) {
      std::cout << "  <option selected value=\"87\">87</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"87\">87</option>" << std::endl;
    }
    if (numops==88) {
      std::cout << "  <option selected value=\"88\">88</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"88\">88</option>" << std::endl;
    }
    if (numops==89) {
      std::cout << "  <option selected value=\"89\">89</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"89\">89</option>" << std::endl;
    }
    if (numops==90) {
      std::cout << "  <option selected value=\"90\">90</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"90\">90</option>" << std::endl;
    }
#endif
#if NUMOPS_MAX>90
    if (numops==91) {
      std::cout << "  <option selected value=\"91\">91</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"91\">91</option>" << std::endl;
    }
    if (numops==92) {
      std::cout << "  <option selected value=\"92\">92</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"92\">92</option>" << std::endl;
    }
    if (numops==93) {
      std::cout << "  <option selected value=\"93\">93</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"93\">93</option>" << std::endl;
    }
    if (numops==94) {
      std::cout << "  <option selected value=\"94\">94</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"94\"94</option>" << std::endl;
    }
    if (numops==95) {
      std::cout << "  <option selected value=\"95\">95</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"95\">95</option>" << std::endl;
    }
    if (numops==96) {
      std::cout << "  <option selected value=\"96\">96</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"96\">96</option>" << std::endl;
    }
    if (numops==97) {
      std::cout << "  <option selected value=\"97\">97</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"97\">97</option>" << std::endl;
    }
    if (numops==98) {
      std::cout << "  <option selected value=\"98\">98</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"98\">98</option>" << std::endl;
    }
    if (numops==99) {
      std::cout << "  <option selected value=\"99\">99</option>" << std::endl;
    } else {
      std::cout << "  <option value=\"99\">99</option>" << std::endl;
    }
#endif
    std::cout << "  </select>" << std::endl;
    std::cout << "  </td>" << std::endl;
    std::cout << "  </tr>" << std::endl;
    std::string currentoutput=string("");
    for (numop=1; numop <=NUMOPS_MAX; numop++) {
      std::string chain;
      std::string operation;
      std::string selected;
      std::string active=std::string("\"display:inline\"");
      std::string lrl_web_data=string(tmp_lrl_web+"/lrl_web_data_"+twodig_array[numop]);
      std::string prioroutput=currentoutput;
      std::string lrl_web_output=string(tmp_lrl_web+"/lrl_web_output_"+twodig_array[numop]+"c");
      std::string currentoutput=lrl_web_output;
      if(numop > numops) active=std::string("\"display:none\"");
      chain_iter =  formData.getElement("chain_"+twodig_array[numop]);
      if (chain_iter == formData.getElements().end()) {
        chain = "";
      } else {
        chain = chain_iter->getValue();
      }
      if (chain.compare("new_input")==0 || numop < 2) {
        lrl_web_data_iter = formData.getElement("lrl_web_data_"+twodig_array[numop]);
      } else {
        lrl_web_data_iter = formData.getElement("lrl_web_output"+twodig_array[numop-1]);
      }
      lrl_web_data_data = lrl_web_data_iter->getValue();
      std::string at=std::string(tmp_lrl_web);
      std::string path=std::string("lrl_web_data_"+twodig_array[numop]);
      if(string_to_file(at.c_str(), path.c_str(), lrl_web_data_data.c_str())) exit(-1);
      if (LRL_WEB_DEBUG) {
        std::cout << "<tr><td colspan=3>" << std::endl;
        std::cout << "/home/"+LRL_WEB_USER+"/public_html/cgi-bin/do_exec_from_buffer.bash "+tmp_lrl_web+"/lrl_web_data_"+twodig_array[numop] <<std::endl;
        std::cout << lrl_web_data_data.c_str() << std::endl; 
        std::cout << "</td></tr>" << std::endl;
      }

      lrl_web_data_file.open(lrl_web_data,ios::trunc);
      lrl_web_data_file << lrl_web_data_data << std::endl;
      lrl_web_data_file.close();
      lrl_web_output_iter = formData.getElement("lrl_web_output"+twodig_array[numop]);
      lrl_web_data_file.open(lrl_web_data);
      operation_iter = formData.getElement("operation_"+twodig_array[numop]);
      if (operation_iter == formData.getElements().end()) {
        operation = "";
      } else {
        operation = operation_iter->getValue();
      }
      std::string oppath=std::string("operation"+twodig_array[numop]);
      if(string_to_file(at.c_str(), oppath.c_str(), operation.c_str())) exit(-1);
      if (LRL_WEB_DEBUG) {
        std::cout << "<tr><td colspan=3>" << std::endl;
        std::cout << "/home/"+LRL_WEB_USER+"/public_html/cgi-bin/do_exec_from_buffer.bash "+tmp_lrl_web+"/operation_"+twodig_array[numop] <<std::endl;
        std::cout << operation.c_str() << std::endl;
        std::cout << "</td></tr>" << std::endl;
      }
      selected = "";
      std::cout << "  <tr>" << std::endl;
      std::cout << "  <td>" << std::endl;
      std::cout << "  <div id=\"block_"+twodig_array[numop]+"\" style="+active+">" << std::endl; 
      std::cout << "  <label for=\"chain_"+twodig_array[numop]+"\">Source of data:</label><br/>" << std::endl;
      std::cout << "  <select name=\"chain_"+twodig_array[numop]+"\" id=\"chain_"+twodig_array[numop]+
          "\" size=\"1\" onchange=\"setchaininput('" << numop << "')\">" << std::endl;
      selected=chain.compare("new_input")==0?"selected ":"";
      std::cout << "  <option "+selected+"value=\"new_input\">use new input</option>" << std::endl;
      selected=chain.compare("chain_input")==0?"selected ":"";
      std::cout << "  <option "+selected+"value=\"chain_input\">use prior output</option>" << std::endl;
      std::cout << "  </select>" << std::endl;
      std::cout << "  </div>" << std::endl;
      std::cout << "  </td>" << std::endl;
      std::cout << "  <td align=left>" << std::endl;
      std::cout << "  <div id=\"block_"+twodig_array[numop]+"a\" style="+active+">" << std::endl; 
      std::cout << "  <label for=\"operation_"+twodig_array[numop]+"\">Select an operation:</label><br/>" << std::endl;
      std::cout << "  <select name=\"operation_"+twodig_array[numop]+"\" id=\"operation_"+twodig_array[numop]+"\" size=\"19\">" << std::endl;
      operationfile << operation << std::endl;
      operationfile.close();
      selected=operation.compare("NoOp")==0?"selected ":"";
      std::cout << "  <option "+selected+"value=\"NoOp\">No operation</option>" << std::endl;
      selected=operation.compare("CmdCmplx")==0?"selected ":"";
      std::cout << "  <option "+selected+"value=\"CmdCmplx\">generate four C6 test cells</option>" << std::endl;
      selected=operation.compare("CmdDelone")==0?"selected ":"";
      std::cout << "  <option "+selected+"value=\"CmdDelone\">compute Selling-reduced primitive cells</option>" << std::endl;
      selected=operation.compare("CmdDists")==0?"selected ":"";
      std::cout << "  <option "+selected+"value=\"CmdDists\">compute NCDist and CS6Dist distances</option>" << std::endl;
      selected=operation.compare("CmdLM")==0?"selected ":"";
      std::cout << "  <option "+selected+"value=\"CmdLM\">apply Lattice Matching algorithm to listed cells</option>" << std::endl;
      selected=operation.compare("CmdNiggli")==0?"selected ":"";
      std::cout << "  <option "+selected+"value=\"CmdNiggli\">compute Niggli-reduced primitive cells</option>" << std::endl;
      selected=operation.compare("CmdPath")==0?"selected ":"";
      std::cout << "  <option "+selected+"value=\"CmdPath\">compute path between pairs of cells</option>" << std::endl;
      selected=operation.compare("CmdPerturb")==0?"selected ":"";
      std::cout << "  <option "+selected+"value=\"CmdPerturb\">compute perturbed versions of input cells</option>" << std::endl;
      selected=operation.compare("CmdS6Refl")==0?"selected ":"";
      std::cout << "  <option "+selected+"value=\"CmdS6Refl\">apply S6 reflections to input cells</option>" << std::endl;
      selected=operation.compare("CmdSella")==0?"selected ":"";
      std::cout << "  <option "+selected+"value=\"CmdSella\"> apply Sella algorithm</option>" << std::endl;
      selected=operation.compare("CmdToB4")==0?"selected ":"";
      std::cout << "  <option "+selected+"value=\"CmdToB4\"> compute Bravais tetrahedron (B4)</option>" << std::endl;
      selected=operation.compare("CmdToC3")==0?"selected ":"";
      std::cout << "  <option "+selected+"value=\"CmdToC3\"> compute Selling-reduced complex cell presentation (C3)</option>" << std::endl;
      selected=operation.compare("CmdToCell")==0?"selected ":"";
      std::cout << "  <option "+selected+"value=\"CmdToCell\"> compute side-angle cells (a, b, c, &alpha;, &beta;, &gamma;)</option>" << std::endl;
      selected=operation.compare("CmdToD13")==0?"selected ":"";
      std::cout << "  <option "+selected+"value=\"CmdToD13\"> compute raw Dirichlet cells (DC13)</option>" << std::endl;
      selected=operation.compare("CmdToDC")==0?"selected ":"";
      std::cout << "  <option "+selected+"value=\"CmdToDC\"> computed sorted Dirichlet cells (DC)</option>" << std::endl;
      selected=operation.compare("CmdToG6")==0?"selected ":"";
      std::cout << "  <option "+selected+"value=\"CmdToG6\"> compute Niggli-reduced cells (G6)</option>" << std::endl;
      selected=operation.compare("CmdToS6")==0?"selected ":"";
      std::cout << "  <option "+selected+"value=\"CmdToS6\"> compute Selling-reduced cells (S6)</option>" << std::endl;
      selected=operation.compare("CmdToU")==0?"selected ":"";
      std::cout << "  <option "+selected+"value=\"CmdToU\"> compute unsorted Dirichlet cells (dc7unsrt)</option>" << std::endl;
      selected=(operation.compare("CmdVolume")==0)?"selected ":"";
      std::cout << "  <option "+selected+"value=\"CmdVolume\"> compute volumes of listed cells</option>" << std::endl;
      std::cout << "  </select>" << std::endl;
      std::cout << "  </div>" << std::endl;
      std::cout << "  </td>" << std::endl;
      std::cout << "  <td align=left>" << std::endl;
      if (chain.compare("new_input")==0 || numop < 2) {
        std::cout << "  <div id=\"block_"+twodig_array[numop]+"b"+"\" style="+active+"> " << std::endl;
      } else {
        std::cout << "  <div id=\"block_"+twodig_array[numop]+"b"+"\" style=\"display:none\" >" <<std::endl;
      }
      std::cout << "  <label for=\"lrl_web_data_"+twodig_array[numop]+"\">Input data:</label><br />" << std::endl;
      std::cout << "  <textarea name=\"lrl_web_data_"+twodig_array[numop]+"\" id=\"lrl_web_data_"
          +twodig_array[numop]+"\" rows=\"9\" cols=\"100\">";
      if (lrl_web_data_iter==formData.getElements().end()) {
          lrl_web_data_data=std::string("end");
      } else {
          lrl_web_data_data=lrl_web_data_iter->getValue();
      }
      std::cout << lrl_web_data_data << std::endl;
      std::cout << "  </textarea>" << std::endl;
      std::cout << "  </div>" << std::endl;
      std::cout << "  <div id=\"block_"+twodig_array[numop]+"c"+"\" style="+active+">" << std::endl;
      std::cout << "  <br />" << std::endl;
      std::cout << "  <label for=\"lrl_web_output_"+twodig_array[numop]+"\">Tool Output:</label><br />" << std::endl;
      std::cout << "  <textarea name=\"lrl_web_output_"+twodig_array[numop]+"\" id=\"lrl_web_output_"+twodig_array[numop]+"\" rows=\"9\" cols=\"100\">" << std::endl;
      std::cout << "  Press submit to process data" << std::endl;
      std::cout << "  </textarea>" << std::endl;
      std::cout << "  </div>" << std::endl;
      std::cout << "  </td>" << std::endl;
      std::cout << "  </tr>" << std::endl;
   }

    std::cout << "    </table>" << std::endl;
    std::cout << "</td>" << std::endl;
    std::cout << "<tr>" << std::endl;
    std::cout << "<td>" << std::endl;
    std::cout << "<center>" << std::endl;
    std::cout << "<INPUT type=\"hidden\" NAME=\"Flush\" VALUE=\"DUMMY\">" << std::endl;
    std::cout << "<INPUT type=\"submit\">" << std::endl;
    std::cout << "<INPUT type=\"reset\">" << std::endl;
    std::cout << "</Form> <hr>" << std::endl;
    std::cout << "</center>" << std::endl;
    std::cout << "</td>" << std::endl;
    std::cout << "</tr>" << std::endl;
    std::cout << "<tr>" << std::endl;
    std::cout << "<td>" << std::endl;
    std::cout << "<a name=\"notice\"><H2 align=\"center\">NOTICE</H2></a>" << std::endl;
    std::cout << "<center>" << std::endl;
    std::cout << "<table border=0>" << std::endl;
    std::cout << "<tr><td width=160>" << std::endl;
    std::cout << "<font size=\"2\">" << std::endl;
    std::cout << "<P>" << std::endl;
    std::cout << "You may redistribute this program under the terms of the <a href=\"gpl.txt\">GPL.</a>" << std::endl;
    std::cout << "<p>" << std::endl;
    std::cout << "Alternatively you may redistribute the functions" << std::endl;
    std::cout << "and subroutines of this program as an API under the" << std::endl;
    std::cout << "terms of the <a href=\"lgpl.txt\">LGPL</a>." << std::endl;
    std::cout << "<p>" << std::endl;
    std::cout << "</td>" << std::endl;
    std::cout << "<td>" << std::endl;
    std::cout << "<div style=\"width:800px;height:150px;overflow:scroll;border:2px solid #0000FF;\">" << std::endl;
    std::cout << "<font size=\"2\">" << std::endl;
    std::cout << "<table border=2>" << std::endl;
    std::cout << "<tr>" << std::endl;
    std::cout << "<th align=\"center\">GPL NOTICES</th>" << std::endl;
    std::cout << "<th align=\"center\">LGPL NOTICES</th></tr>" << std::endl;
    std::cout << "<tr><td><font size=\"2\">" << std::endl;
    std::cout << "This program is free software; you can redistribute it and/or" << std::endl;
    std::cout << "modify it under the terms of the GNU General Public License as" << std::endl;
    std::cout << "published by the Free Software Foundation; either version 2 of" << std::endl;
    std::cout << "(the License, or (at your option) any later version." << std::endl;
    std::cout << "<p>" << std::endl;
    std::cout << "This program is distributed in the hope that it will be useful," << std::endl;
    std::cout << "but WITHOUT ANY WARRANTY; without even the implied warranty of" << std::endl;
    std::cout << "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the" << std::endl;
    std::cout << "GNU General Public License for more details." << std::endl;
    std::cout << "<p>" << std::endl;
    std::cout << "You should have received a copy of the GNU General Public License" << std::endl;
    std::cout << "along with this program; if not, write to the Free Software" << std::endl;
    std::cout << "Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA" << std::endl;
    std::cout << "02111-1307  USA</font>" << std::endl;
    std::cout << "</td>" << std::endl;
    std::cout << "<td><font size=\"2\">" << std::endl;
    std::cout << "This library is free software; you can redistribute it and/or" << std::endl;
    std::cout << "modify it under the terms of the GNU Lesser General Public" << std::endl;
    std::cout << "License as published by the Free Software Foundation; either" << std::endl;
    std::cout << "version 2.1 of the License, or (at your option) any later version." << std::endl;
    std::cout << "<p>" << std::endl;
    std::cout << "This library is distributed in the hope that it will be useful," << std::endl;
    std::cout << "but WITHOUT ANY WARRANTY; without even the implied warranty of" << std::endl;
    std::cout << "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU" << std::endl;
    std::cout << "Lesser General Public License for more details." << std::endl;
    std::cout << "<p>" << std::endl;
    std::cout << "You should have received a copy of the GNU Lesser General Public" << std::endl;
    std::cout << "License along with this library; if not, write to the Free" << std::endl;
    std::cout << "Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston," << std::endl;
    std::cout << "MA  02110-1301  USA</font>" << std::endl;
    std::cout << "</td>" << std::endl;
    std::cout << "</tr>" << std::endl;
    std::cout << "</table>" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "<P>" << std::endl;
    std::cout << "<STRONG>" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Some of the software and documents included within this software package are the intellectual property of" << std::endl; 
    std::cout << "various parties, and placement in this package does not in anyway imply that any such rights have in any " << std::endl;
    std::cout << "way been waived or diminished." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "<P>" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "With respect to any software or documents for which a copyright exists, ALL RIGHTS ARE RESERVED TO THE" << std::endl;
    std::cout << "OWNERS OF SUCH COPYRIGHT." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "<P>" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Even though the authors of the various documents and software found here have made a good faith effort to" << std::endl; 
    std::cout << "ensure that the documents are correct and that the software performs according to its documentation, and " << std::endl;
    std::cout << "we would greatly appreciate hearing of any problems you may encounter, the programs and documents any " << std::endl;
    std::cout << "files created by the programs are provided **AS IS** without any warrantee as to correctness, " << std::endl;
    std::cout << "merchantability or fitness for any particular or general use." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "<P>" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "THE RESPONSIBILITY FOR ANY ADVERSE CONSEQUENCES FROM THE USE OF PROGRAMS OR DOCUMENTS OR ANY FILE OR FILES" << std::endl; 
    std::cout << "CREATED BY USE OF THE PROGRAMS OR DOCUMENTS LIES SOLELY WITH THE USERS OF THE PROGRAMS OR DOCUMENTS OR " << std::endl;
    std::cout << "FILE OR FILES AND NOT WITH AUTHORS OF THE PROGRAMS OR DOCUMENTS." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "</STRONG>" << std::endl;
    std::cout << "</font>" << std::endl;
    std::cout << "</div>" << std::endl;
    std::cout << "</td>" << std::endl;
    std::cout << "</tr>" << std::endl;
    std::cout << "</table>" << std::endl;
    std::cout << "</center>" << std::endl;
    std::cout << "<P>" << std::endl;
    std::cout << "<hr>" << std::endl;
    std::cout << "</font>" << std::endl;
    std::cout << "<a name=\"source\"></a>" << std::endl;
    std::cout << "<H2>Access to the source of LRL_WEB</H2>" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "<p>" << std::endl;
    std::cout << "<a name=\"references\"></a>" << std::endl;
    std::cout << "<h2>References</h2>" << std::endl;
    std::cout << "<p>" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "<a name=\"Andrews1988\">[1]</a> L. C. Andrews and H. J. Bernstein. Lattices and reduced cells as points in" << std::endl; 
    std::cout << "6-space and selection of Bravais lattice type by projections. Acta Crystallogr., A44:10091018, 1988.<br />" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "<a name=\"Andrews2012\">[2]</a> L. C. Andrews and H. J. Bernstein. The Geometry of Niggli Reduction. arXiv," << std::endl; 
    std::cout << "1203.5146v1 [math-ph], 2012. <a href=\"http://arxiv.org/abs/1203.5146\">arxiv.org/abs/1203.5146</a>.<br />" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "<a name=\"Zimmermann1985\">[3]</a> H. Zimmermann and H. Burzlaff. DELOS A computer program for the" << std::endl; 
    std::cout << "determination of a unique conventional cell. Zeitschrift f&uuml;r Kristallographie, 170:241 246, 1985." << std::endl;
    std::cout << "<p>" << std::endl;
    std::cout << "<hr />" << std::endl;
    std::cout << "</center>" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "<hr>" << std::endl;
    std::cout << "Updated 26 August 2023." << std::endl;
    std::cout << "</font>" << std::endl;
 }

