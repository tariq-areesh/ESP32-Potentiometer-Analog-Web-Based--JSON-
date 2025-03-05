window.onload = function() {
    async function fetchData() {
        try {
            let response = await fetch("http://(esp_ip)/data"); 
            let json = await response.json();
            document.getElementById("value").textContent = json.value;
        } catch (error) {
            document.getElementById("value").textContent = "Fetch Error";
        }
    }
    setInterval(fetchData, 500); 
    fetchData(); 
}
