<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <meta http-equiv="x-ua-compatible" content="ie=edge">
  <title>SmartContract Verification</title>
  <meta name="description" content="">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="css/bootstrap.min.css">
  <link rel="stylesheet" href="css/font-awesome.min.css">
  <link rel="stylesheet" href="css/normalize.css">
  <link rel="stylesheet" href="css/main.css">
  <link rel="stylesheet" href="css/style.css">
  <script src="js/vendor/modernizr-2.8.3.min.js"></script>
  <script src="js/vendor/jquery-1.12.0.min.js"></script>
  <script src="bootstrap-3.3.7/js/bootstrap.min.js"></script>
  <script src="bootstrap-3.3.7/js/bootstrap.js" ></script>
  <!-- <link href="jquery.highlight-within-textarea.css" rel="stylesheet">
  <script src="jquery.highlight-within-textarea.js"></script> -->
  <script src= "https://cdnjs.cloudflare.com/ajax/libs/codemirror/5.48.4/codemirror.js"></script>
  <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/codemirror/5.48.4/codemirror.min.css">
  <script src= "https://cdnjs.cloudflare.com/ajax/libs/codemirror/5.48.4/mode/clike/clike.min.js"></script>
  <script src= "https://cdnjs.cloudflare.com/ajax/libs/codemirror/5.48.4/mode/javascript/javascript.min.js"></script>
  <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/codemirror/5.48.4/theme/base16-dark.css">
  <script src= "https://cdnjs.cloudflare.com/ajax/libs/codemirror/5.48.4/addon/edit/closebrackets.js"></script>

  <script type="text/javascript">

  </script>
</head>
<body>
    <!-- <style>
        rightAlg{float:right;height:50px;padding:15px 15px;font-size:18px;line-height:20px}
    </style> -->


<div class="main">
  <div class="row">
    <div class="col-sm-12">
      <nav class="shadow navbar navbar-inverse navbar-fixed-top nbar">
        <div class="navbar-header">
          <a class="navbar-brand" href="index.php">&nbsp;&nbsp;&nbsp; SmartContract Verifier</a>
          <a class="navbar-brand" href="#bottom" style="font-size: 15px;">&emsp;&emsp;&emsp;&emsp;&emsp;&emsp; &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;
              &emsp;&emsp;&emsp;&emsp;&emsp;&emsp; &emsp;&emsp;&emsp;&emsp;&emsp;&emsp; &emsp;&emsp;&emsp;&emsp;&emsp;&emsp; &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;
              &emsp;&emsp;&emsp;&emsp;&emsp;&emsp; &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp; &emsp;&emsp; Team</a>
          <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-menubuilder"><span class="sr-only">Toggle navigation</span><span class="icon-bar"></span><span class="icon-bar"></span><span class="icon-bar"></span>
              </button>
        </div>
        <div class="collapse navbar-collapse navbar-menubuilder">
          <ul class="nav navbar-nav">
          </ul>
        </div>
      </nav>
    </div>
  </div>
  <br><br>
  <br>

  <div class="pagetitle"><h3><b>KLEE for Smart Contracts</b></h3>
  </div>

  <div class="form-group">

    <form action="compile.php" name="f2" method="POST" enctype="multipart/form-data">
      <div>
          <label for="input-file">Upload Contract File </label>
          <input type="file" id="input-file" name="input-file" value="Upload Contract" onchange="loadfile(this)">
      </div>
      <br>

      <style>
       /* .rownr {overflow-y: hidden; background-color: rgb(105,105,105); color: white;
               text-align: right; vertical-align:top} */
       .txt {width: 95%; overflow-x: scroll}

      </style>
      <div>
        <span>
          <textarea class="try" name="content-target" id="content-target"
          rows="19" cols="60" style="width: 700px; height: 380px;"
          spellcheck="false" autocapitalize="off" autocorrect="off"></textarea>

         </span>
      </div>

      <script type = "text/javascript">

      // ---------------
      // for dislpaying uploaded file in textarea

      const editor = CodeMirror.fromTextArea(document.getElementById('content-target'), {
          lineNumbers: true,
          mode: "javascript",
          theme: "base16-dark",
          indentWithTabs: true,
          autoCloseTags: true,
          autoCloseBrackets: true
      });
      editor.setSize(900, 400);

      document.getElementById('input-file').addEventListener('change', loadfile)

      function loadfile(event){
          const input = event.target;
          var reader = new FileReader();
          reader.readAsText(input.files[0]);
          reader.onload = function(){ editor.setValue(reader.result); }
          var fullPath = $("#input-file").val();
          var filename = fullPath.replace(/^.*[\\\/]/, '');
      }
       //------------------

      </script>

      <br>
      <input type="submit" class="btn btn-success" value="Verify" style="width: 100px; height: 50px"><br><br><br>
    </form>
  </div>
</div>

<br><br><br>
  <div class="area" id="bottom">
    <div class="well foot">
      <div class="row area">
        <div class="col-sm-5">
          <div class="fm">
            <b>Beta Version-2020</b><br>
            <b>Developed By <a href="https://www.linkedin.com/in/namratajain690/">Namrata Jain</a></b>
          </div>
        </div>

        <div class="col-sm-4">
            <div class="fm">
                <b>Contributors</b><br>
                <b> <a href="https://subodhvsharma.github.io/">Subodh Sharma</a></b> <br>
                <b> <a href="https://cs.kyushu-u.ac.jp/en/organization/fcs/kosuke-kaneko/">Kosuke Kaneko</a></b> <br>
                <b> <a href="https://www.linkedin.com/in/namratajain690/">Namrata Jain</a></b>
                <br> <br>
                <address>
                    <b><a href="mailto:namratajain690@gmail.com">Contact Us</a>.<br></b>
                </address>
            </div>
        </div>

        <!-- <div class="col-sm-4">
            <div class="fm">
            <address>
                <b><a href="mailto:namratajain690@gmail.com">Contact Us</a>.<br></b>
            </address>
            </div>
        </div> -->

        <!-- <div class="col-sm-4">
            <div class="fm">
          <?php
            // date_default_timezone_set("Asia/Kolkata");
            // $t=date("H:i:s");
            // echo"<b>Server Time:  $t</b>";
          ?>
            </div>
        </div> -->
      </div>
    </div>
  </div>

</body>
</html>
