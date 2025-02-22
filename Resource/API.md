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

---
---

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


# API-related interview
here are some important topics and discussions that might come up, along with explanations and sample answers.

---

## **1. REST vs SOAP vs GraphQL vs gRPC**
Understanding the differences between API architectures is crucial.

| Feature       | REST | SOAP | GraphQL | gRPC |
|--------------|------|------|---------|------|
| **Protocol** | HTTP | HTTP, SMTP, TCP | HTTP | HTTP/2 |
| **Data Format** | JSON, XML | XML | JSON | Protobuf |
| **Flexibility** | Medium | Low | High | High |
| **Performance** | Good | Slower (more overhead) | Better than REST | High (binary) |
| **Use Case** | Web APIs | Enterprise apps | Dynamic queries | Microservices |

🔹 **Example Question:** *What are the advantages of GraphQL over REST?*  
**Answer:** GraphQL allows clients to request only the data they need, reducing over-fetching and under-fetching. It also supports multiple resource queries in a single request, improving efficiency.

---

## **2. API Authentication & Authorization**
Common authentication methods:
- **API Keys** → Simple, but can be insecure if exposed.
- **OAuth 2.0** → Industry standard for authentication.
- **JWT (JSON Web Tokens)** → Secure, self-contained authentication.
- **Basic Auth** → Username & password in headers.
- **Session-based Auth** → Used with cookies.

🔹 **Example Question:** *What is the difference between authentication and authorization?*  
**Answer:**  
- **Authentication** verifies who you are (e.g., logging in with a password).  
- **Authorization** determines what you can do (e.g., admin vs. user permissions).

---

## **3. Caching in REST APIs**
Caching improves performance by storing frequent responses.

🔹 **Methods of Caching:**
- **Client-Side Caching** → Browser stores data.
- **Server-Side Caching** → API responses are cached using Redis or Memcached.
- **Proxy Caching** → CDNs like Cloudflare cache responses.

🔹 **Example Question:** *How does caching work in REST APIs?*  
**Answer:** REST APIs use cache control headers like:
```http
Cache-Control: max-age=3600, public
ETag: "abc123"
```
This allows clients to reuse responses instead of making new requests.

---

## **4. Idempotency in REST APIs**
🔹 **What is idempotency?**  
A request is idempotent if making it multiple times has the same effect as making it once.

| Method   | Idempotent? | Description |
|----------|------------|-------------|
| **GET**  | ✅ | No changes occur. |
| **PUT**  | ✅ | Updates a resource, replacing existing content. |
| **DELETE** | ✅ | Deleting the same resource multiple times has the same effect. |
| **POST**  | ❌ | Creates a new resource each time. |

🔹 **Example Question:** *Why should DELETE be idempotent?*  
**Answer:** If you send multiple DELETE requests for the same resource, it should be deleted only once. Idempotency ensures consistent API behavior.

---

## **5. API Rate Limiting & Throttling**
Rate limiting prevents API abuse by restricting the number of requests a client can make in a given time.

🔹 **Common Methods:**
- **Fixed Window** → Limits requests per fixed time (e.g., 100 requests per minute).
- **Sliding Window** → More flexible, resets limits gradually.
- **Token Bucket** → Allows bursts of requests but refills tokens at a constant rate.

🔹 **Example Question:** *How would you implement rate limiting in an API?*  
**Answer:** Using a middleware like Nginx, Redis, or API Gateway (AWS API Gateway, Cloudflare) to enforce limits:
```http
HTTP/1.1 429 Too Many Requests
Retry-After: 60
```
This tells the client to wait 60 seconds before retrying.

---

## **6. API Versioning**
APIs change over time, so versioning helps maintain backward compatibility.

🔹 **Common Versioning Strategies:**
1. **URL Versioning:** `GET /v1/users`
2. **Header Versioning:** `Accept: application/vnd.myapi.v1+json`
3. **Query Parameter Versioning:** `GET /users?version=1`
4. **Subdomain Versioning:** `v1.api.example.com`

🔹 **Example Question:** *Which API versioning method do you prefer and why?*  
**Answer:** URL versioning (`/v1/users`) is the most common and easy to implement, but header-based versioning provides a cleaner URL structure.

---

## **7. Error Handling in REST APIs**
Proper error handling improves API reliability.

🔹 **Common HTTP Status Codes for Errors:**
- `400 Bad Request` → Invalid request parameters.
- `401 Unauthorized` → Missing or invalid authentication.
- `403 Forbidden` → The user does not have permission.
- `404 Not Found` → Resource does not exist.
- `422 Unprocessable Entity` → Validation failed.
- `500 Internal Server Error` → Server-side issue.

🔹 **Example Question:** *What should an API return when a user requests a non-existent resource?*  
**Answer:** A `404 Not Found` status with a JSON response:
```json
{
  "error": "Resource not found",
  "code": 404
}
```

---

## **8. API Security Best Practices**
🔹 **Common Security Measures:**
- Use **HTTPS** for secure communication.
- Implement **JWT or OAuth2** for authentication.
- Use **rate limiting** to prevent DDoS attacks.
- Sanitize input to prevent **SQL injection** and **XSS**.
- Validate and **escape user input**.
- Restrict CORS policies (`Access-Control-Allow-Origin`).

🔹 **Example Question:** *How do you prevent API security vulnerabilities?*  
**Answer:**
1. **Use HTTPS** to encrypt traffic.
2. **Implement authentication** with JWT/OAuth2.
3. **Use API gateways** for throttling.
4. **Sanitize input** to prevent SQL injection.
5. **Limit CORS** to trusted origins.

---

## **9. API Testing (Postman, cURL, Automated)**
🔹 **Testing Tools:**
- **Postman** → GUI-based API testing.
- **cURL** → Command-line testing.
- **Jest/Supertest** → Automated API testing in JavaScript.
- **RestAssured** → API testing in Java.

🔹 **Example Question:** *How would you test an API endpoint?*  
**Answer:** Using cURL:
```sh
curl -X GET "https://api.example.com/users/1" -H "Authorization: Bearer token"
```
Or using Postman for structured API testing.

---

## **10. WebSockets vs REST**
🔹 **Key Differences:**
| Feature       | REST | WebSockets |
|--------------|------|------------|
| **Communication** | Request-Response | Full-duplex |
| **Stateful?** | No (stateless) | Yes |
| **Best For** | Standard APIs | Real-time apps (chat, gaming) |

🔹 **Example Question:** *When should you use WebSockets instead of REST?*  
**Answer:** WebSockets should be used for real-time applications like chat apps, live notifications, and stock market updates because they provide persistent, low-latency connections.

---

## **Final Interview Tips**
1. **Know your HTTP methods & status codes** well.
2. **Explain REST principles** (stateless, resource-based URLs, etc.).
3. **Be ready to discuss security** (OAuth, JWT, rate limiting).
4. **Understand real-world API design decisions** (versioning, error handling).
5. **Practice API testing** with Postman and cURL.


---
---
# **Final Interview Tips** 

---

## **1. Know Your HTTP Methods & Status Codes Well**
HTTP methods and status codes are fundamental in API design. You should be able to explain their purpose and when to use them.

### **Important HTTP Methods:**
| Method   | Usage |
|----------|-------------------------------------------------|
| **GET**  | Retrieve data from the server (idempotent). |
| **POST** | Create a new resource (not idempotent). |
| **PUT**  | Update or replace a resource (idempotent). |
| **PATCH** | Partially update a resource (not necessarily idempotent). |
| **DELETE** | Remove a resource (idempotent). |

🔹 **Example Question:** *When should you use PUT vs PATCH?*  
✅ **Answer:**  
- **PUT** is used when replacing an entire resource. Example:
  ```http
  PUT /users/1
  Content-Type: application/json
  {
    "name": "John Doe",
    "email": "john@example.com"
  }
  ```
  This will replace the entire user object.
  
- **PATCH** is used for partial updates. Example:
  ```http
  PATCH /users/1
  Content-Type: application/json
  {
    "email": "newemail@example.com"
  }
  ```
  This updates only the email field.

---

### **Common HTTP Status Codes & Their Use Cases:**
| Code | Meaning | When to Use? |
|------|---------|-------------|
| **200 OK** | Success | When the request succeeds and data is returned. |
| **201 Created** | Resource Created | When a new resource is successfully created. |
| **204 No Content** | Success, No Response | When an action succeeds, but no response body is needed (e.g., DELETE). |
| **400 Bad Request** | Client Error | When the request is invalid due to incorrect input. |
| **401 Unauthorized** | Auth Required | When authentication is missing or incorrect. |
| **403 Forbidden** | Access Denied | When the user does not have permission to access a resource. |
| **404 Not Found** | Resource Missing | When the requested resource doesn’t exist. |
| **409 Conflict** | Data Conflict | When there is a conflict in data (e.g., duplicate entry). |
| **500 Internal Server Error** | Server Issue | When the server fails to process the request. |

🔹 **Example Question:** *What’s the difference between 401 and 403?*  
✅ **Answer:**  
- **401 Unauthorized** → The user needs to authenticate but hasn’t.  
- **403 Forbidden** → The user is authenticated but doesn’t have permission.

---

## **2. Explain REST Principles**
REST (Representational State Transfer) follows key architectural principles to ensure scalable and efficient APIs.

### **Key REST Principles:**
1. **Statelessness:**  
   - The server does not store client session data.
   - Each request must contain all necessary information (e.g., authentication tokens).
   - Example:  
     ```http
     GET /orders/123
     Authorization: Bearer abc123
     ```
     The token must be provided with each request.

2. **Resource-Based URLs:**  
   - API endpoints represent **nouns** (resources) rather than verbs.
   - Example:  
     ✅ `GET /users/123` → Correct  
     ❌ `GET /getUser?id=123` → Bad practice

3. **Use of HTTP Methods Properly:**  
   - **GET** for retrieval, **POST** for creation, **PUT/PATCH** for updating, **DELETE** for deletion.

4. **Client-Server Separation:**  
   - The front-end (client) and back-end (server) should be independent.

5. **Layered System:**  
   - API architecture can include load balancers, caching layers, and security gateways without affecting client interaction.

🔹 **Example Question:** *Why is REST considered stateless?*  
✅ **Answer:** Because each request contains all the necessary data, and the server does not store client state between requests. This improves scalability.

---

## **3. Be Ready to Discuss Security (OAuth, JWT, Rate Limiting)**
API security is crucial to prevent unauthorized access and data breaches.

### **1️⃣ OAuth 2.0 (Authorization)**
OAuth is a secure way to **delegate access**.  
🔹 Example: A user logs into an app using their **Google account**.

**OAuth 2.0 Flow:**
1. The user logs in with Google.
2. Google **redirects** to the app with an authorization code.
3. The app exchanges the code for an **access token**.
4. The token is used in API requests for authentication.

🔹 **Example OAuth Request:**
```http
GET /user
Authorization: Bearer ACCESS_TOKEN
```

---

### **2️⃣ JSON Web Token (JWT)**
JWT is used for **authentication** and is stateless.

**JWT Structure:**
`Header.Payload.Signature`
Example JWT:
```json
{
  "alg": "HS256",
  "typ": "JWT"
}
.
{
  "user_id": 123,
  "role": "admin"
}
.
"signature"
```

🔹 **Example Question:** *Why use JWT instead of session-based authentication?*  
✅ **Answer:** JWT is stateless and does not require server-side storage. Sessions, on the other hand, require the server to track users.

---

### **3️⃣ Rate Limiting**
Prevents abuse by limiting how many requests a client can send.

🔹 Example: **Allowing 100 requests per minute per user.**

**Implementation Example in Express.js:**
```js
const rateLimit = require('express-rate-limit');
const limiter = rateLimit({
  windowMs: 60 * 1000, // 1 minute
  max: 100 // limit each IP to 100 requests per minute
});
app.use(limiter);
```

🔹 **Example Question:** *How do you prevent API abuse?*  
✅ **Answer:** Using **rate limiting, authentication, API keys, and monitoring**.

---

## **4. Understand Real-World API Design Decisions**
APIs must be designed for scalability, maintainability, and flexibility.

### **1️⃣ API Versioning**
Why? **APIs evolve, but breaking changes should not affect existing users.**
- **URL Versioning:** `/v1/users`
- **Header Versioning:** `Accept: application/vnd.myapi.v1+json`

🔹 **Example Question:** *How do you handle breaking changes in an API?*  
✅ **Answer:** Introduce **versioning** and deprecate old versions gradually.

---

### **2️⃣ Error Handling**
APIs should return **meaningful error messages**.

🔹 **Bad Example (Generic Response):**
```json
{
  "error": "Something went wrong"
}
```

🔹 **Good Example (Detailed Response):**
```json
{
  "error": "Invalid email format",
  "code": 422,
  "details": "Email should contain '@' symbol"
}
```

🔹 **Example Question:** *How do you handle errors in REST APIs?*  
✅ **Answer:** Use structured error responses and meaningful status codes.

---

## **5. Practice API Testing with Postman and cURL**
API testing ensures that endpoints work as expected.

### **1️⃣ Using Postman**
- Import APIs via **OpenAPI (Swagger)**.
- Automate testing with **collections**.
- Set **environment variables** for authentication.

### **2️⃣ Using cURL (CLI Testing)**
🔹 **Example cURL Request:**
```sh
curl -X GET "https://api.example.com/users/1" -H "Authorization: Bearer token"
```

🔹 **Example Question:** *How do you test an API endpoint?*  
✅ **Answer:** Using **Postman for GUI testing** and **cURL for CLI testing**.

---

## **Final Thoughts**
- **Master HTTP methods & status codes** 🚀
- **Understand REST principles** 📌
- **Learn OAuth, JWT, and security best practices** 🔐
- **Know versioning & error handling strategies** ⚡
- **Practice API testing with Postman & cURL** 🛠️
