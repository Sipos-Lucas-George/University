// Define the menu data
const menuData = [
    {
        title: "Submenu 1",
        components: ["Component 1", "Component 2", "Component 3"],
    },
    {
        title: "Submenu 2",
        components: ["Component 1", "Component 2", "Component 3"],
    },
    {
        title: "Submenu 3",
        components: ["Component 1", "Component 2", "Component 3"],
    },
    {
        title: "Submenu 4",
        components: ["Component 1", "Component 2", "Component 3"],
    },
    {
        title: "Submenu 5",
        components: ["Component 1", "Component 2", "Component 3"],
    },
];

const menuElement = document.getElementById("menu");
menuElement.style.cssText =
    "width: 200px;background-color: #eee;padding: 10px;border-radius: 10px;";

menuData.forEach((submenu) => {
    const titleElement = document.createElement("a");
    titleElement.href = "#";
    titleElement.style.cssText =
        "display: block;text-decoration: none;color: #333;padding: 5px;margin: 5px 0;border-radius: 5px;font-size:25px;";
    titleElement.textContent = submenu.title;
    menuElement.appendChild(titleElement);

    const componentsElement = document.createElement("div");
    componentsElement.classList.add("submenu");
    componentsElement.style.cssText = "display:none";
    submenu.components.forEach((component) => {
        const componentElement = document.createElement("a");
        componentElement.href = "#";
        componentElement.style.cssText =
            "display: block;text-decoration: none;color: #333;padding: 5px;margin: 5px 0;border-radius: 5px;";
        componentElement.textContent = component;
        componentsElement.appendChild(componentElement);
    });
    menuElement.appendChild(componentsElement);
});
const menuItems = document.querySelectorAll("#menu > a");
const submenus = document.querySelectorAll(".submenu");

menuItems.forEach((menuItem, index) => {
    menuItem.addEventListener("click", () => {
        submenus.forEach((submenu) => {
            submenu.style.display = "none";
        });
        submenus[index].style.display = "block";
    });
});
