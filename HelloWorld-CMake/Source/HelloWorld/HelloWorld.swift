
import HelloWorldCore

struct HelloWorldStringAccessor {
  func access() throws -> String? {
    return HelloWorldCore.string
  }
}

func display(_ message: String) -> Bool {
  print(message)
  return true
}

func main() {
  let accessor: HelloWorldStringAccessor = HelloWorldStringAccessor()
  guard let message = try? accessor.access(), display(message!) else {
    print("unable to display message")
    return
  }
}

main()

