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
        <script src= "https://cdnjs.cloudflare.com/ajax/libs/codemirror/5.48.4/mode/clike/clike.js"></script>
        <script src= "https://cdnjs.cloudflare.com/ajax/libs/codemirror/5.48.4/mode/javascript/javascript.js"></script>
        <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/codemirror/5.48.4/theme/base16-dark.css">


</head>
<body>
<div class="main">
<div class="row">
<div class="col-sm-12">
<nav class="navbar navbar-inverse navbar-fixed-top nbar">
    <div class="navbar-header">
      <a class="navbar-brand" href="index.php">&nbsp;&nbsp;&nbsp;SmartContract Verifier</a>
    </div>
    <ul class="nav navbar-nav">
      <!-- <li class="space"><a href="compiler.php"><i class="fa fa-code ispace"></i>Compiler</a></li>
      <li class="space"><a href="archive.php"><i class="fa fa-archive ispace"></i>Problem Archive</a></li>
      <li class="space"><a href="contest.php"><i class="fa fa-cogs ispace"></i>Contests</a></li>
      <li class="space"><a href="debug.php"><i class="fa fa-check-square ispace"></i>Debug</a></li>
      -->
    </ul>

</nav>
</div>
</div>
<br> <br> <br>
<div class="pagetitle"><h3><b>Verification Results</b></h3>
</div>

    <style>
     /* .rownr {overflow-y: hidden; background-color: rgb(105,105,105); color: white;
             text-align: right; vertical-align:top} */
     .txt {width: 95%; overflow-x: scroll}

     .button {
          background-color: green; /* Green */
          border: none;
          color: white;
          padding: 10px 15px;
          text-align: center;
          text-decoration: none;
          display: inline-block;
          font-size: 16px;
      }

      .grid-container {
          display: grid;
          height: auto;
          width: auto;
          align-content: right;
          grid-template-columns: 650px;
          grid-gap: 10px;
          background-color: #ccc;
          padding: 20px;
        }

      .grid-container > div {
          background-color: #ccc;
          text-align: left;
          padding: 10px;
          font-size: 15px;
          height: auto;
          width: auto;
        }
        pre {
            display: block;
            font-family: monospace;
            white-space: pre;
            margin: 1em 0;
            height:auto;
            width:1160px;
        }

    </style>

    <?php
        if(isset($_POST['content-target'])){
            if (($_FILES['input-file']['name']!="")){
                $filename=$_FILES['input-file']['name'];
            }
            else {
                echo "File not found";
                echo "\n";
            }

            $contents = $_POST['content-target'];
            $old_path = getcwd();
            chdir('/home/namrata/klee/tools/klee/');
            // $old = umask(0);
            // echo $old;
            // // echo getcwd();
            // $file = "BPUseNet.sol";

            // chmod($file, 0777);
            // // $open = file_get_contents('index.php');
            // // echo $open;
            //
            // // $saved_File = fopen($file, 'w+');
            // // fwrite($saved_File, $contents);
            // // fclose($saved_File);
            //
            // //use chmod 777 <dirname> in which file is to be created
            if(file_put_contents($filename, $contents) === false)
                echo "Error while writing smart contract to server.";
            chmod($filename, 0777);
            chdir($old_path);
      }
    ?>

    <br>
            <b> <?php echo $filename ?></b>
            <br>
            <textarea readonly id="content-target" name="content-target" ><?php
                    $old_path = getcwd();
                    chdir('/home/namrata/klee/tools/klee/');
                    echo file_get_contents($filename);
                    chdir($old_path);
            ?></textarea>

            <script>

            const solidityCode = CodeMirror.fromTextArea(document.getElementById('content-target'), {
                lineNumbers: true,
                mode: "javascript",
                theme: "base16-dark",
                readOnly: "true"
            });
            solidityCode.setSize(900, 400);

            </script>

            <?php
                $old_path = getcwd();
                chdir('/home/namrata/klee/tools/klee/');
                $output1 = shell_exec("./runKLEE.sh '{$filename}' 2>&1");
                $output2 = shell_exec("./getResult.sh 2>&1");
                chdir($old_path);
            ?>


            <br>
            <b> <?php echo "convertedFile.cpp" ?></b>
            <br>

            <textarea readonly id="content-target-cpp" name="content-target-cpp" ><?php
                    $old_path = getcwd();
                    chdir('/home/namrata/klee/tools/klee/');
                    echo file_get_contents('convertedFile.cpp');
                    chdir($old_path);
            ?></textarea>

            <script>

            const cppCode = CodeMirror.fromTextArea(document.getElementById('content-target-cpp'), {
                lineNumbers: true,
                mode: "text/x-c++src",
                theme: "base16-dark",
                readOnly: "true"
            });
            cppCode.setSize(900, 400);

            </script>
        <!-- </div> -->
    <br><br><br>

    <div class = "grid-container">
        <div>
              <?php
                echo "<pre>$output1</pre>";
                echo "<pre><b>$output2</b></pre>";
             ?>
        </div>
    </div>
</div>

<br><br><br><br><br><br><br>

  <div class="area">
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
      </div>
    </div>
  </div>


</body>
</html>
