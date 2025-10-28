// === DOM Elements ===
const form = document.getElementById("resumeForm");
const generateBtn = document.getElementById("generateBtn");
const clearBtn = document.getElementById("clearBtn");
const regenBtn = document.getElementById("regenBtn");
const statusEl = document.getElementById("status");
const pdfPreview = document.getElementById("pdfPreview");
const noPreview = document.getElementById("noPreview");
const downloadLink = document.getElementById("downloadLink");

// === State Variables ===
let lastBlobUrl = null;
let lastPayload = null;
let itemCounter = 0; // Used to ensure unique IDs for dynamically added fields

// === UI Helpers ===

/**
 * Sets the status message displayed to the user.
 * @param {string} text - The message content.
 * @param {boolean} isError - True if the message is an error.
 */
function setStatus(text, isError = false) {
    statusEl.classList.remove("visually-hidden");
    statusEl.textContent = text;
    statusEl.style.color = isError ? "#d32f2f" : "#0b6e4f";
    statusEl.style.borderColor = isError ? "#fecaca" : "#bbf7d0";
    statusEl.style.backgroundColor = isError ? "#fef2f2" : "#f0fdf4";

    // Remove previous error log if present
    const existingLog = statusEl.parentNode.querySelector("pre.log");
    if (existingLog) {
        existingLog.remove();
    }
}

/** Clears the status message. */
function clearStatus() {
    statusEl.classList.add("visually-hidden");
    statusEl.textContent = "";
}

/** Revokes the URL object created for the last PDF blob to free up memory. */
function revokeLastBlob() {
    if (lastBlobUrl) {
        URL.revokeObjectURL(lastBlobUrl);
        lastBlobUrl = null;
    }
}

/**
 * Displays the generated PDF blob in the iframe and updates the download link.
 * @param {Blob} blob - The PDF file blob.
 */
function showPdfBlob(blob) {
    revokeLastBlob();
    const url = URL.createObjectURL(blob);
    lastBlobUrl = url;

    pdfPreview.src = url;
    pdfPreview.style.display = "block";
    noPreview.style.display = "none";

    // Update download link
    downloadLink.href = url;
    downloadLink.classList.remove("disabled");
    downloadLink.classList.add("primary");
}

/** Resets the PDF preview area and download link to their initial states. */
function resetPreview() {
    revokeLastBlob();
    pdfPreview.src = "";
    pdfPreview.style.display = "none";
    noPreview.style.display = "block";

    downloadLink.href = "#";
    downloadLink.classList.remove("primary");
    downloadLink.classList.add("disabled");
}

// === Dynamic Form Management (NEW) ===

/**
 * Creates the HTML structure for a single dynamic item (e.g., work, project).
 * @param {string} className - The class name (e.g., 'work-item', 'education-item').
 * @param {number} count - The item number for display.
 * @returns {string} The HTML string for the new item.
 */
function createItemHtml(className, count) {
    const fields = {
        'work-item': [
            { field: 'company', label: 'Company', placeholder: 'TechCorp Inc.' },
            { field: 'title', label: 'Job Title', placeholder: 'Software Engineer' },
            { field: 'duration', label: 'Duration (e.g., 2020 - Present)', placeholder: '2020 - Present' },
            { field: 'description', label: 'Key Achievements/Responsibilities', placeholder: 'Achieved X, responsible for Y.' }
        ],
        'project-item': [
            { field: 'name', label: 'Project Name', placeholder: 'Portfolio Website' },
            { field: 'link', label: 'Link (Optional)', placeholder: 'https://project.com' },
            { field: 'description', label: 'Description', placeholder: 'Technologies used and impact.' }
        ],
        'education-item': [
            { field: 'institution', label: 'Institution', placeholder: 'University of Tech' },
            { field: 'degree', label: 'Degree/Certificate', placeholder: 'M.S. in Computer Science' },
            { field: 'dates', label: 'Dates (e.g., 2018 - 2020)', placeholder: '2018 - 2020' },
        ],
        'volunteer-item': [
            { field: 'organization', label: 'Organization', placeholder: 'Code for Community' },
            { field: 'role', label: 'Role', placeholder: 'Volunteer Developer' },
            { field: 'description', label: 'Description', placeholder: 'What you did and its impact.' }
        ]
    };

    const type = className.split('-')[0];
    const itemTitle = type.charAt(0).toUpperCase() + type.slice(1);
    
    let html = `
        <div class="${className} dynamic-group" id="${className}-${itemCounter}">
            <p class="group-title">${itemTitle} #${count} <button type="button" class="remove-btn" data-target-id="${className}-${itemCounter}">Remove</button></p>
    `;

    for (const { field, label, placeholder } of fields[className] || []) {
        html += `
            <div class="input-group">
                <label for="${field}-${itemCounter}">${label}</label>
                <${field === 'description' ? 'textarea rows="3"' : 'input type="text"'} 
                    id="${field}-${itemCounter}" 
                    data-field="${field}" 
                    placeholder="${placeholder}"
                ></${field === 'description' ? 'textarea' : 'input'}>
            </div>
        `;
    }

    html += `</div>`;
    return html;
}

/** Handles clicking the "+ Add Item" buttons. */
function handleAddItem(e) {
    const btn = e.target;
    const groupClassName = btn.dataset.group; // e.g., 'work-item'
    const fieldset = btn.closest('fieldset');

    // Get the current number of items of this class
    const currentCount = fieldset.querySelectorAll(`.${groupClassName}`).length;
    itemCounter++;

    // Create the new item HTML
    const newHtml = createItemHtml(groupClassName, currentCount + 1);
    
    // Insert the new item before the "Add" button
    btn.insertAdjacentHTML('beforebegin', newHtml);

    // Re-attach listeners for the new "Remove" button
    attachRemoveListeners();
}

/** Handles clicking the "Remove" buttons. */
function handleRemoveItem(e) {
    const btn = e.target;
    const targetId = btn.dataset.targetId;
    const targetElement = document.getElementById(targetId);
    
    if (targetElement) {
        targetElement.remove();
        
        // After removal, re-number the remaining items in the group
        const groupClassName = targetElement.classList[0]; // e.g., 'work-item'
        const fieldset = targetElement.closest('fieldset');
        const remainingItems = fieldset.querySelectorAll(`.${groupClassName}`);

        remainingItems.forEach((item, index) => {
            // Update the display number in the group-title
            const titleEl = item.querySelector('.group-title');
            if (titleEl) {
                const type = groupClassName.split('-')[0];
                const itemTitle = type.charAt(0).toUpperCase() + type.slice(1);
                titleEl.innerHTML = `${itemTitle} #${index + 1} <button type="button" class="remove-btn" data-target-id="${item.id}">Remove</button>`;
            }
        });
        
        // Re-attach listeners for the updated remove buttons
        attachRemoveListeners();
    }
}

/** Attaches click listeners to all current "Remove" buttons. */
function attachRemoveListeners() {
    document.querySelectorAll('.remove-btn').forEach(btn => {
        // Remove previous listener to prevent duplication
        btn.removeEventListener('click', handleRemoveItem); 
        btn.addEventListener('click', handleRemoveItem);
    });
}


// === Form Data Collection (Original + Cleanup) ===

/** Collects and structures all user data from the form inputs. */
function collectFormData() {
    // Helper to get trimmed text value
    const val = (id) => document.getElementById(id)?.value.trim() || "";

    // Helper to collect data from dynamic, repeating form groups (e.g., work-item)
    const collectGroup = (className) =>
        Array.from(document.querySelectorAll(`.${className}`)).map((el) => {
            const obj = {};
            // Iterate over all inputs with data-field attribute within the group
            for (const input of el.querySelectorAll("[data-field]")) {
                obj[input.dataset.field] = input.value.trim();
            }
            return obj;
        }).filter(item => Object.values(item).some(v => v !== "")); // Filter out groups where all fields are empty

    // Helper for comma-separated lists like skills
    const listFromInput = (id) =>
        val(id)
            .split(",")
            .map((s) => s.trim())
            .filter((s) => s);

    return {
        promptType: "resume",
        userData: {
            name: val("name"),
            email: val("email"),
            summary: val("summary"),
            work_experience: collectGroup("work-item"),
            projects: collectGroup("project-item"),
            volunteering: collectGroup("volunteer-item"),
            education: collectGroup("education-item"),
            skills: listFromInput("skills")
        }
    };
}


// === API Communication ===

/**
 * Sends the payload to the backend API for PDF generation.
 * @param {object} payload - The structured data to send.
 * @returns {Promise<object>} An object containing the result (ok, blob, or error).
 */
async function postGenerate(payload) {
    try {
        console.log("Sending payload:", payload);

        const res = await fetch("/api/generate", {
            method: "POST",
            headers: { "Content-Type": "application/json" },
            body: JSON.stringify(payload),
        });

        console.log("Response received:", res);

        const contentType = res.headers.get("Content-Type") || "";

        if (!res.ok) {
            const bodyText = await res.text();
            console.error("Error Response:", bodyText);
            // Attempt to parse JSON error message or fall back to status/text
            try {
                const json = JSON.parse(bodyText);
                throw new Error(json.error || JSON.stringify(json));
            } catch {
                throw new Error(bodyText || `HTTP ${res.status}`);
            }
        }

        // Handle PDF (success) response
        if (contentType.includes("application/pdf")) {
            const blob = await res.blob();
            console.log("PDF blob received:", blob);
            return { ok: true, blob };
        }

        // Handle JSON (likely a non-PDF success/log response)
        if (contentType.includes("application/json")) {
            const json = await res.json();
            console.log("JSON response:", json);
            return {
                ok: json.success || false,
                error: json.error || "Unknown error",
                log: json.log || null,
            };
        }

        const text = await res.text();
        return { ok: false, error: text || "Unknown non-pdf response" };

    } catch (err) {
        console.error("Request failed:", err);
        return { ok: false, error: err.message || String(err) };
    }
}

// === Animation and Status Management ===

/**
 * Displays an animating dot loader next to the status message.
 * @param {string} baseText - The text to display before the dots.
 * @returns {function} A function to call to stop the animation.
 */
function animateDots(baseText) {
    let dots = 0;
    const interval = setInterval(() => {
        dots = (dots + 1) % 4;
        setStatus(`${baseText}${Array(dots).fill(".").join("")}`);
    }, 500);
    return () => clearInterval(interval);
}

// === Event Handlers ===

/** Main form submission handler (Generate & Compile). */
form.addEventListener("submit", async (e) => {
    e.preventDefault();
    clearStatus();
    resetPreview();

    const payload = collectFormData();
    lastPayload = payload;

    generateBtn.disabled = true;
    generateBtn.textContent = "Generating...";

    const stopAnim = animateDots("Generating PDF");
    setStatus("Sending request to backend...");

    const res = await postGenerate(payload);

    stopAnim();
    generateBtn.disabled = false;
    generateBtn.textContent = "Generate & Compile";

    if (res.ok && res.blob) {
        setStatus("PDF generated successfully!");
        // The API should ideally return the PDF directly, not a download URL,
        // which the Flask backend should handle by sending the file.
        // We assume the successful call returns the PDF blob.
        showPdfBlob(res.blob); 
    } else {
        setStatus(`Error: ${res.error || "unknown"}`, true);

        // Display detailed backend log if available
        if (res.log) {
            const pre = document.createElement("pre");
            pre.className = "log";
            pre.textContent = res.log;
            statusEl.parentNode.appendChild(pre);
        }
    }
});

/** Form reset handler. */
clearBtn.addEventListener("click", (e) => {
    e.preventDefault();
    form.reset();
    
    // Clear dynamic items, except the initial one if needed
    document.querySelectorAll('.dynamic-group').forEach(el => el.remove());
    
    clearStatus();
    resetPreview();
});

/** Regenerate button handler (uses last successful payload). */
regenBtn.addEventListener("click", async (e) => {
    e.preventDefault();
    if (!lastPayload) {
        setStatus("No previous data to regenerate.", true);
        return;
    }

    clearStatus();
    setStatus("Regenerating with same inputs...");
    generateBtn.disabled = true;
    generateBtn.textContent = "Generating...";

    const stopAnim = animateDots("Regenerating PDF");
    const res = await postGenerate(lastPayload);
    stopAnim();

    generateBtn.disabled = false;
    generateBtn.textContent = "Generate & Compile";

    if (res.ok && res.blob) {
        setStatus("PDF regenerated successfully!");
        showPdfBlob(res.blob);
    } else {
        setStatus(`Error: ${res.error || "unknown"}`, true);
    }
});

// === Initial Setup ===

function initialize() {
    resetPreview();
    clearStatus();
    
    // Attach listeners for adding new items
    document.querySelectorAll('.add-item-btn').forEach(btn => {
        btn.addEventListener('click', handleAddItem);
    });
    
    // Attach listeners for removing initial items (if any exist in HTML)
    attachRemoveListeners();
}

initialize();
