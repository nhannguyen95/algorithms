## What it's used for?
- this pattern ENSUREs a class has only 1 instance, and provides a global point of access to it.
- this pattern is meant to be used sparingly.

## How to use?
- A raw implementation:
  ```java
  public class Singleton {
    private static Singleton instance = null;
    
    private Singleton() {};
    
    public static Singleton getInstance() {
      if (instance == null) {
        instance = new Singleton();
      }
      return instance;
    }
  }
  ```
  
- Problem: if multiple threads call `getInstance` for the first time at the same time, multiple instances could be created.

- Solution:
  
  We could make the `getInstance` method synchronized, but synchronization is expensive:
  ```java
  public static synchronized Singleton getInstance() {}
  ```
  
  Actually, we only need to synchornize when the `instance` is still null, thus we can instantiate `instance` eagerly`:
  ```java
  private static Singleton instance = new Singleton();
  ```
  
  or we can synchronize only the needed part:
  ```java
  public static Singleton getInstance() {
    if (instance == null) {
      // Sync this
    }
    return instance;
  }
  ```
