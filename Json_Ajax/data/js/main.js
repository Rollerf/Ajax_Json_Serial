function sendData() {
  var xhttp = new XMLHttpRequest();

  let ledNumber = document.getElementById('ledNumber');
  let ledStatus = document.querySelector('input[name="status"]:checked');
  let ledData = {
    id: ledNumber.value,
    status: ledStatus.value
  }
  let data = JSON.stringify(ledData);

  xhttp.addEventListener('load', function (event) {
    console.log('OK', xhttp);
  });

  xhttp.addEventListener('error', function (event) {
    console.log('error', xhttp);
  });

  xhttp.open('POST', 'LED');
  xhttp.setRequestHeader('Content-Type', 'application/json');
  xhttp.send(data);
}

function getData() {
  var xhttp = new XMLHttpRequest();

  xhttp.onreadystatechange = function () {
    if (xhttp.readyState == XMLHttpRequest.DONE) {
      if (xhttp.status == 200) {
        console.log((xhttp.responseText));
        let json = JSON.parse(xhttp.responseText);
        console.log();

        let receivedMsg = 'Received: Id ' + json.id + ' ' + (json.status == 1 ? "ON" : "OFF");

        switch (json.id) {
          case 1:
            document.getElementById('receivedId1').textContent = receivedMsg;
            break;
          case 2:
            document.getElementById('receivedId2').textContent = receivedMsg;
            break;
          case 3:
            document.getElementById('receivedId3').textContent = receivedMsg;
            break;
          case 4:
            var elem = document.getElementById("myBar");
            elem.style.width = json.progress + "%";
            elem.innerHTML = json.progress + "%";
            document.getElementById('receivedId4').textContent = receivedMsg;
            break;
          default:
            console.log('error', xhttp);
            break;
        }
      }
    }
  };

  xhttp.open("GET", "LED", true);
  xhttp.send();
}

(function scheduleAjax() {
  getData();
  setTimeout(scheduleAjax, 500);
})();