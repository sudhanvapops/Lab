function renderFolder(folder) {
    console.log(folder.name);

    for (const child of folder.children) {
        console.log("  " + child.name);

    }
}


renderFolder(folder)