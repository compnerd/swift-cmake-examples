
@_implementationOnly
import CCore

public struct HelloWorldCore {
  public static var string: String {
    return _HelloWorldCore.string
  }

  public static var version: String {
    return "\(CGetVersionMajor()).\(CGetVersionMinor()).\(CGetVersionPatch())"
  }
}

