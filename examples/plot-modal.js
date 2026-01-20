// plot-modal.js

function getModal() {
    return document.getElementById("img-modal");
}

function getModalImg() {
    return document.getElementById("img-modal-img");
}

function onAnyCloseEvent() {
    closeModal();
}

function onKeyCloseEvent(e) {
    if (e.key === "Escape") closeModal();
}

function openModal(src, alt) {
    const modal = getModal();
    const img = getModalImg();
    if (!modal || !img) return;

    img.src = src;
    img.alt = alt || "";

    modal.classList.add("is-open")
    modal.addEventListener("click", onAnyCloseEvent, { capture: true, once: true });
    document.addEventListener("keydown", onKeyCloseEvent, { once: true });
}

function closeModal() {
    const modal = getModal();
    if (!modal) return;
    modal.classList.remove("is-open")
    modal.addEventListener("click", onAnyCloseEvent, { capture: true, once: true });
    
    const img = getModalImg();
    if (!img) return;
    img.src = "";
    img.alt = "";
}


function onDocumentClick(e) {
    const link = e.target.closest("a.plot-thumb");
    if (!link) return;

    e.preventDefault();

    const img = link.querySelector("img");
    const alt = (img && img.alt) || link.getAttribute("aria-label") || "";

    openModal(link.href, alt);
}

document.addEventListener("DOMContentLoaded", () => {
    document.addEventListener("click", onDocumentClick);
});

