<?php
require 'Page.inc';

class NewYear2014 extends Page
{
  function __construct()
  {
     parent::__construct("New Year 2014");
  }

  public function Display()
  {
    echo "<html>\n<head>\n";
    $this->displayTitle();
    $this->displayJS();
    $this->displayStyle();
    $this->displayBody();
    
    echo "</head>\n</html>\n";
  }
  
  protected function displayTitle()
  {
  ?>
    <title>New Year 2014</title>
  <?php
  }


  protected function displayJS()
  {
    ?>
    <script type="text/javascript">
      var decisionTimeUCT = new Date();
      decisionTimeUCT.setUTCDate(18);
      decisionTimeUCT.setUTCFullYear(2014);
      decisionTimeUCT.setUTCHours(0);
      decisionTimeUCT.setUTCMilliseconds(0);
      decisionTimeUCT.setUTCMinutes(0);
      decisionTimeUCT.setUTCMonth(11);
      decisionTimeUCT.setUTCSeconds(0);

      var newYear = new Date(2015, 0, 1, 0, 0, 0, 0);

      function displayChar()
      {
        // var now=new Date();
        var now=new Date();

        if(now.getTime() >= decisionTimeUCT.getTime())
        {
            document.getElementById('charspinner').innerHTML=getChosenButton();
        }
        else
        {
            document.getElementById('charspinner').innerHTML=getRandomChar();
            t=setTimeout(function(){displayChar()},200); // Call again in 200 milliseconds  
        }
      }

      function getChosenButton()
      {
        return '<form action="ResultPage"> <input type="submit" value="See Letter"></form>';
      }

      function displayTime()
      {
        // CURRENT TIME //
        var now = new Date();

        document.getElementById('countdown_new_year').innerHTML=getTimeDifference(now, newYear);////newYearUCT); // Time remaining until new year
        document.getElementById('countdown_decision_time').innerHTML=getTimeDifference(now, decisionTimeUCT);//decisionTimeUCT); // Time remaining until decision

        t=setTimeout(function(){displayTime()},500); // Call again in half a second
      }

      function getTimeDifference(from,to)
      {
        var oneSecInMs = 1000;
        var oneMinuteInMs = oneSecInMs*60;
          var oneHourInMs = oneMinuteInMs*60;
        var oneDayInMs = oneHourInMs*24; 
        var timeRemaining = to.getTime() - from.getTime();
        var daysRemaining = make2Digit(timeRemaining / oneDayInMs | 0);
          var hoursRemaining = make2Digit((timeRemaining - (daysRemaining * oneDayInMs)) / oneHourInMs | 0);
          var minutesRemaining = make2Digit((timeRemaining - (daysRemaining * oneDayInMs) - (hoursRemaining * oneHourInMs)) / oneMinuteInMs | 0);
        var secRemaining = make2Digit((timeRemaining - (daysRemaining * oneDayInMs) 
          - (hoursRemaining * oneHourInMs) - (minutesRemaining * oneMinuteInMs)) / oneSecInMs | 0);

        return daysRemaining+" Days, " + hoursRemaining+ " Hours, " + minutesRemaining+" Minutes, " + secRemaining+" Seconds "
      }

      function getRandomChar()
      {
        return String.fromCharCode(Math.random() * 26 + 65);
      }

      function make2Digit(i)
      { if(i < 0)
          return "00";
        if(i < 10)
          return ("0" + i);

        return i;
      }

      function startThreads()
      {
        displayChar(); // Displays random characters
        displayTime(); // Manages the display of the time
      }
    </script>
  <?php
  }
  
  protected function displayStyle()
  {
  ?>
    <style type="text/css">
      body {
        background-color: #F2F4E6;
      }
      @font-face {
        font-family: Alternate_Gothic_No2;
        src: url('fonts/Alternate Gothic No2 BT.ttf'), 
        url('fonts/Alternate Gothic No2 BT.ttf'); /* IE */
      }
      .center{
        margin-left:auto;
        margin-right:auto;
        width:50%;
      }
      .center_align{
        text-align: center;
      }
      .right_align{
        text-align: right;
      }
      .new_year_heading{
        color: rgba(84,18,64,0.5);
        font-size:80;
        font-weight:bold;
      }
      .alternate_gothic{
        font-family:Alternate_Gothic_No2;
      }
      .test {
        font: 30 Helvetica, Sans-Serif;
        letter-spacing: -1px;
        color: rgba(0,0,255,0.5); 
      }
      .space_under > td{
        padding-bottom: 2em;
      }
      .after {
        color: rgba(255,0,0,0.5);   
      }
      #charspinner{
        font-weight:bold;
        font-size:100;
      }
    </style>
  <?php
  }

  protected function displayBody()
  {
    ?>
      <body onload="startThreads()">
      <h1 class="center center_align new_year_heading alternate_gothic"> New Year 2014</h1>
      <p class="center_align test after" > <span id="countdown_new_year"></span> until new year</p>  
        <p class="center_align test after"> <span id="countdown_decision_time"></span> until random letter selection</p>  
        <table class="center center_align">
          <tr class="space_under">
            <td><img src="./pictures/alexandra.yeterian.jpg"/></td>
            <td><img src="./pictures/fiona.brand.106.jpg"/></td>
            <td><img src="./pictures/nina.holden.9.jpg"/></td>
          </tr>
          <tr class="space_under">
            <td><img src="./pictures/mbmbmb111111.jpg"/></td>
            <td><span class="align_center alternate_gothic" id="charspinner"></span></td>
            <td><img src="./pictures/harry.long1.jpg"/></td>
          </tr>
          <tr class="space_under">
            <td><img src="./pictures/sdecasson.jpg"/></td>
            <td><img src="./pictures/taylor.jpg" width="100" height="125"></td>
            <td><img src="./pictures/thomas.w.hopkins.jpg"/></td>
          </tr>
        </table>
      </body>
    <?php
  }
  
  protected function displayFooter()
  {
    
  }
}