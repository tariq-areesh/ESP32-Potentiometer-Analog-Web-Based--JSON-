window.onload = function() {
    async function fetchData() {
        try {
            let response = await fetch("http://192.168.8.194/data"); 
            let json = await response.json();
            document.getElementById("value").textContent = json.value;
        } catch (error) {
            document.getElementById("value").textContent = "Fetch Error";
        }
    }
    setInterval(fetchData, 500); 
    fetchData(); 
}