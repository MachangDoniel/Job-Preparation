# HTTP (Hypertext Transfer Protocol)
- defines various methods (also called verbs) to indicate the desired action to be performed on a resource. Below is a detailed explanation of all the HTTP methods:

---

### **1. GET**
- **Purpose:** Retrieves data from the server.
- **Characteristics:**
  - Should not change the resource (idempotent).
  - Can be cached.
  - Parameters are sent in the URL (query string).
- **Example:**
  ```http
  GET /users?id=123 HTTP/1.1
  Host: example.com
  ```
- **Use Case:** Fetching user details, loading web pages.

---

### **2. POST**
- **Purpose:** Submits data to the server to create or update a resource.
- **Characteristics:**
  - Not idempotent (multiple requests can create multiple resources).
  - Request body contains data.
  - Usually changes the server state.
- **Example:**
  ```http
  POST /users HTTP/1.1
  Host: example.com
  Content-Type: application/json

  {
    "name": "Alice",
    "email": "alice@example.com"
  }
  ```
- **Use Case:** Creating a new user, submitting a form.

---

### **3. PUT**
- **Purpose:** Updates or creates a resource at a specific URL.
- **Characteristics:**
  - Idempotent (same request gives the same result).
  - Replaces the entire resource if it exists.
- **Example:**
  ```http
  PUT /users/123 HTTP/1.1
  Host: example.com
  Content-Type: application/json

  {
    "name": "Alice Updated",
    "email": "alice@example.com"
  }
  ```
- **Use Case:** Updating a user profile.

---

### **4. PATCH**
- **Purpose:** Partially updates a resource.
- **Characteristics:**
  - Not necessarily idempotent.
  - Only modifies specified fields instead of replacing the entire resource.
- **Example:**
  ```http
  PATCH /users/123 HTTP/1.1
  Host: example.com
  Content-Type: application/json

  {
    "name": "Alice Updated"
  }
  ```
- **Use Case:** Changing a specific attribute of a user.

---

### **5. DELETE**
- **Purpose:** Deletes a resource.
- **Characteristics:**
  - Idempotent (deleting the same resource multiple times results in the same state).
  - Usually does not return a body.
- **Example:**
  ```http
  DELETE /users/123 HTTP/1.1
  Host: example.com
  ```
- **Use Case:** Removing a user from a system.

---

### **6. HEAD**
- **Purpose:** Retrieves headers of a resource without the body.
- **Characteristics:**
  - Used to check metadata like content length, type, or status.
  - Idempotent.
- **Example:**
  ```http
  HEAD /users/123 HTTP/1.1
  Host: example.com
  ```
- **Use Case:** Checking if a resource exists before making a GET request.

---

### **7. OPTIONS**
- **Purpose:** Retrieves allowed HTTP methods for a resource.
- **Characteristics:**
  - Used for CORS (Cross-Origin Resource Sharing) checks.
- **Example:**
  ```http
  OPTIONS /users HTTP/1.1
  Host: example.com
  ```
- **Response:**
  ```http
  HTTP/1.1 200 OK
  Allow: GET, POST, PUT, DELETE, OPTIONS
  ```
- **Use Case:** Checking what methods a resource supports.

---

### **8. TRACE**
- **Purpose:** Echoes the received request for debugging.
- **Characteristics:**
  - Used to diagnose network issues.
  - Rarely used due to security risks.
- **Example:**
  ```http
  TRACE /users HTTP/1.1
  Host: example.com
  ```
- **Use Case:** Debugging request paths.

---

### **9. CONNECT**
- **Purpose:** Establishes a tunnel to the server (used for HTTPS proxies).
- **Characteristics:**
  - Used for SSL/TLS tunneling.
  - Commonly used in proxies.
- **Example:**
  ```http
  CONNECT example.com:443 HTTP/1.1
  Host: example.com
  ```
- **Use Case:** Secure communication via proxy servers.

---

### **Summary Table:**
| Method   | Idempotent | Safe | Request Body | Use Case |
|----------|------------|------|--------------|-----------|
| **GET**  | ✅ | ✅ | ❌ | Fetch data |
| **POST** | ❌ | ❌ | ✅ | Create a resource |
| **PUT**  | ✅ | ❌ | ✅ | Replace a resource |
| **PATCH**| ❌ | ❌ | ✅ | Partially update a resource |
| **DELETE**| ✅ | ❌ | ❌ | Remove a resource |
| **HEAD** | ✅ | ✅ | ❌ | Get metadata |
| **OPTIONS** | ✅ | ✅ | ❌ | Check allowed methods |
| **TRACE** | ✅ | ✅ | ❌ | Debug request |
| **CONNECT** | ❌ | ❌ | ❌ | Secure tunneling |



# HTTP status codes 
- commonly used in RESTful APIs, categorized based on their purpose.

---

## **1xx - Informational Responses**
These indicate that the request has been received and is being processed.

| Code | Meaning | Description |
|------|---------|------------|
| **100** | Continue | The server has received the request headers and is waiting for the rest of the request. |
| **101** | Switching Protocols | The server is switching protocols as requested (e.g., HTTP to WebSockets). |
| **102** | Processing | The server is processing but has not yet completed the request. |

---

## **2xx - Success Responses**
These indicate that the request was successfully received, understood, and accepted.

| Code | Meaning | Description |
|------|---------|------------|
| **200** | OK | The request was successful, and the server returns the requested data. |
| **201** | Created | A new resource was successfully created. |
| **202** | Accepted | The request has been accepted for processing but is not yet completed. |
| **203** | Non-Authoritative Information | The response is from a third-party source, not the original server. |
| **204** | No Content | The request was successful, but there is no content in the response. |
| **205** | Reset Content | Similar to 204, but instructs the client to reset the view. |
| **206** | Partial Content | Only part of the requested content is returned (used for range requests). |
| **207** | Multi-Status | Used in WebDAV, returns multiple response statuses for batch processing. |

---

## **3xx - Redirection Responses**
These indicate that further action is needed to complete the request.

| Code | Meaning | Description |
|------|---------|------------|
| **300** | Multiple Choices | Multiple options for the resource are available. |
| **301** | Moved Permanently | The requested resource has been permanently moved to a new URL. |
| **302** | Found (Temporary Redirect) | The resource is temporarily located elsewhere. |
| **303** | See Other | The response should be retrieved from another URI. |
| **304** | Not Modified | The resource has not changed (used for caching). |
| **307** | Temporary Redirect | Similar to 302, but the method must remain unchanged. |
| **308** | Permanent Redirect | Similar to 301, but the method must remain unchanged. |

---

## **4xx - Client Errors**
These indicate that the client made a request that the server cannot process.

| Code | Meaning | Description |
|------|---------|------------|
| **400** | Bad Request | The request is invalid or malformed. |
| **401** | Unauthorized | Authentication is required but not provided or incorrect. |
| **402** | Payment Required | Reserved for future use (sometimes used for paid APIs). |
| **403** | Forbidden | The server refuses to fulfill the request despite authentication. |
| **404** | Not Found | The requested resource does not exist. |
| **405** | Method Not Allowed | The requested method (e.g., `POST`, `GET`) is not supported for this resource. |
| **406** | Not Acceptable | The server cannot return data in the requested format. |
| **407** | Proxy Authentication Required | The client must authenticate with a proxy first. |
| **408** | Request Timeout | The request took too long, and the server closed the connection. |
| **409** | Conflict | The request conflicts with the current state of the resource. |
| **410** | Gone | The resource is permanently removed and will not be available again. |
| **411** | Length Required | The request must include a `Content-Length` header. |
| **412** | Precondition Failed | A precondition in the request headers is not met. |
| **413** | Payload Too Large | The request body is too large for the server to handle. |
| **414** | URI Too Long | The requested URI is too long for the server to process. |
| **415** | Unsupported Media Type | The request media type is not supported (e.g., sending XML when JSON is required). |
| **416** | Range Not Satisfiable | The requested range cannot be fulfilled (e.g., asking for bytes that don’t exist in a file). |
| **417** | Expectation Failed | The server cannot meet the expectations defined in the request headers. |
| **418** | I'm a Teapot | A joke response from RFC 2324 (not commonly used). |
| **422** | Unprocessable Entity | The request is syntactically correct but has semantic errors (e.g., invalid data input). |
| **423** | Locked | The resource is locked and cannot be modified. |
| **424** | Failed Dependency | The request depends on another request that failed. |
| **426** | Upgrade Required | The client must upgrade to a newer protocol version (e.g., TLS). |
| **429** | Too Many Requests | The client has sent too many requests in a short time (rate-limiting). |

---

## **5xx - Server Errors**
These indicate that the server encountered an error while processing the request.

| Code | Meaning | Description |
|------|---------|------------|
| **500** | Internal Server Error | A generic error message for unexpected server failures. |
| **501** | Not Implemented | The server does not support the requested functionality. |
| **502** | Bad Gateway | The server received an invalid response from an upstream server. |
| **503** | Service Unavailable | The server is temporarily overloaded or under maintenance. |
| **504** | Gateway Timeout | The server did not receive a timely response from another server. |
| **505** | HTTP Version Not Supported | The server does not support the HTTP version used in the request. |
| **507** | Insufficient Storage | The server does not have enough storage to fulfill the request. |
| **508** | Loop Detected | The request caused an infinite loop on the server. |
| **510** | Not Extended | Further extensions to the request are required. |

---

## **Commonly Used Status Codes in REST APIs**
- **200 OK** → Request was successful (GET, POST, DELETE).
- **201 Created** → Resource was successfully created (POST).
- **204 No Content** → Successful request, but no response body (DELETE).
- **400 Bad Request** → The client sent invalid data.
- **401 Unauthorized** → Authentication is required.
- **403 Forbidden** → The user is not allowed to access the resource.
- **404 Not Found** → The resource does not exist.
- **409 Conflict** → Data conflict, such as duplicate entries.
- **422 Unprocessable Entity** → Validation errors on input data.
- **429 Too Many Requests** → Rate-limiting applied.
- **500 Internal Server Error** → The server encountered an error.

