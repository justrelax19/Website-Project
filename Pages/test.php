<?php 
@ini_set("output_buffering", "Off");
@ini_set('implicit_flush', 1);
@ini_set('zlib.output_compression', 0);
@ini_set('max_execution_time',1200);


header( 'Content-type: text/html; charset=utf-8' );


echo "Testing time out in seconds\n";
for ($i = 0; $i < 1150; $i++) {
    echo $i." -- ";

    if(sleep(1)!=0)
    {
        echo "sleep failed script terminating"; 
        break;
    }
    flush();
    ob_flush();
}

?>